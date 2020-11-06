#include "main.h"
#include "drive.hpp"
#include "tarvis/api.hpp"

// todo spell check comments
void initialize() { pros::lcd::initialize(); }
void disabled()
{
    tarvis::System::autonDeInits();
    tarvis::System::userDeInits();
}
void competition_initialize() {}
void autonomous()
{
    tarvis::System::autonInits(); // init all systems for autonomus control
}
void opcontrol()
{
    tarvis::System::userInits(); // init all systems for user control
    uint32_t prev = pros::millis();
    while (true)
    {
        tarvis::System::userCallstacks(); // loop through all user call stacks
        pros::Task::delay_until(&prev, 10);
        // the maximum refresh of the motors is 20_ms, so might as well save some battery
    }
}