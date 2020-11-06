#include "drive.hpp"
#include <cmath>
Drive &drive = Drive::get();
Drive &Drive::get()
{
    static Drive instance = Drive();
    return instance;
}
Drive::Drive()
{
    front_left_wheel.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    front_right_wheel.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    back_left_wheel.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    back_right_wheel.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

    front_left_wheel.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
    front_right_wheel.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
    back_left_wheel.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
    back_right_wheel.setEncoderUnits(AbstractMotor::encoderUnits::degrees);

    front_left_wheel.setGearing(AbstractMotor::gearset::green);
    front_right_wheel.setGearing(AbstractMotor::gearset::green);
    back_left_wheel.setGearing(AbstractMotor::gearset::green);
    back_right_wheel.setGearing(AbstractMotor::gearset::green);

    front_left_wheel.tarePosition();
    front_right_wheel.tarePosition();
    back_left_wheel.tarePosition();
    back_right_wheel.tarePosition();
}
void Drive::autonCallstack() {}
void Drive::autonInit()
{
    userDeInit();

    rampX.start();
    rampY.start();
    rampZ.start();
}
void Drive::autonDeInit()
{
    rampX.suspend();
    rampY.suspend();
    rampZ.suspend();
}

void Drive::userCallstack()
{
    // user functions to call in main loop
}
void Drive::userInit() { autonDeInit(); }
void Drive::userDeInit() {}

bool Drive::isSettled(int v)
{
    return (std::abs(front_left_wheel.getActualVelocity()) < v) &&
           (std::abs(front_right_wheel.getActualVelocity()) < v) &&
           (std::abs(back_left_wheel.getActualVelocity()) < v) && (std::abs(back_right_wheel.getActualVelocity()) < v);
}
double Drive::getYPos() { return back_left_wheel.getPosition(); }

void Drive::moveY(double distance, double speed, int timeout, int endWait)
{ // assumes velocity start = end = 0
    double direction;
    double targetDeg = distance * 360 / wheelCir;

    direction = (targetDeg - getYPos()) > 0 ? 1 : -1;
    int velocity = std::abs(speed) * direction;
    rampY.request(velocity);
    if (direction > 0)
    {
        while (back_left_wheel.getPosition() < targetDeg)
        {
            pros::delay(motorUpdateRate);
        }
    }
    else
    {
        while (back_left_wheel.getPosition() > targetDeg)
        {
            pros::delay(motorUpdateRate);
        }
    }
    rampY.request(0);
    while (isSettled(1))
    {
        pros::delay(motorUpdateRate);
    }
}