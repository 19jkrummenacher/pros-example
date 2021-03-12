#include "main.h"
#include "drive.hpp"
#include "feed.hpp"
#include "intake.hpp"
#include "hardware.hpp"
#include "routines.hpp"

// todo spell check comments
namespace auton
{
    void Task(void *why)
    {
        uint32_t prevMsec = pros::millis();
        while (true)
        {
            drive::auton::ramping();
            feed::auton::execute();
            intake::auton::execute();
            pros::Task::delay_until(&prevMsec, 10); // delay for 5 millis exact
        }
    }
    pros::Task autonTask(Task, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "AutonTask");
} // namespace auton

void initialize()
{
  pros::lcd::initialize();
  feed::frontOptical.set_led_pwm(50);
  feed::backOptical.set_led_pwm(50);
 }
void disabled() { auton::autonTask.suspend(); }
void competition_initialize() {}
void autonomous()
{
    drive::set_brakeMode(okapi::Motor::brakeMode::hold);
    drive::LeftN.instant(0);
    drive::RightN.instant(0);
    drive::LeftS.instant(0);
    drive::RightS.instant(0);
    auton::autonTask.resume();
    pros::lcd::set_text(1,"hello autonomous");
    intake::auton::autoIntakeOpen(true, 2000);
    //routines::auton2();
}
void opcontrol()
{
    auton::autonTask.suspend();
    drive::set_brakeMode(okapi::Motor::brakeMode::coast);
    uint32_t prev = pros::millis();
    pros::lcd::set_text(1,"hello driver");
    while (true)
    {
        drive::control::manual();
      //  drive::control::hold();

        intake::control::user();
        feed::control::user();

        pros::Task::delay_until(&prev, 10);
        // the maximum refresh of the motors is 20_ms, so might as well save some battery
    }
}
