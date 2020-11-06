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
void Drive::autonCallstack()
{
    //? uncoment these blocks if you want to run all of the drive ramping calcultions in one task
    // rampX.calculate();
    // rampY.calculate();
    // rampZ.calculate();

    // front_left_wheel.moveVelocity(rampY.output() + rampX.output() + rampZ.output());
    // front_right_wheel.moveVelocity(rampY.output() - rampX.output() - rampZ.output());
    // back_left_wheel.moveVelocity(rampY.output() - rampX.output() + rampZ.output());
    // back_right_wheel.moveVelocity(rampY.output() + rampX.output() - rampZ.output());
}
void Drive::autonInit()
{
    userDeInit();

    //? coment if you want to run all of the drive ramping calcultions in one task
    rampX.start();
    rampY.start();
    rampZ.start();
}
void Drive::autonDeInit()
{
    //? comment if you want to run all of the drive ramping calcultions in one task
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

double Drive::getYDeg()
{ // deg
    return (front_left_wheel.getPosition() + front_right_wheel.getPosition() + back_left_wheel.getPosition() +
            back_right_wheel.getPosition()) /
           4;
}
double Drive::getXDeg()
{ // deg
    return (front_left_wheel.getPosition() - front_right_wheel.getPosition() - back_left_wheel.getPosition() +
            back_right_wheel.getPosition()) /
           4;
}
double Drive::getZDeg()
{ // deg
    return (front_left_wheel.getPosition() - front_right_wheel.getPosition() + back_left_wheel.getPosition() -
            back_right_wheel.getPosition()) /
           (4 * 360) * (wheelCir / ((length / 2) + (width / 2)) * (180 / M_PI));
}

void Drive::wait(int endWait, double vSettled, int timeout, bool y, bool x, bool z)
{ // bool yxz is for what to stop and wait for

    // request drive to stop
    if (y) rampY.request(0);
    if (x) rampX.request(0);
    if (z) rampZ.request(0);
    while (y ? rampY.output() != 0 : false || x ? rampX.output() != 0 : false || z ? rampZ.output() != 0 : false)
    {
        pros::delay(motorUpdateRate);
    }
    // drive has been requested to stop
    // wait for drive to actualy come to a stop/settle with a timeout incase of error
    const int tStart = pros::millis();
    while (!isSettled(vSettled) && pros::millis() < tStart + timeout)
    { // wait for the actual velocity to be acceptiable with in the time out window
        pros::delay(motorUpdateRate);
    }
    // drive is actualy settled or timeout has happened
    pros::delay(endWait);
}
void Drive::moveY(double distance, double velocity, int timeout, int endWait)
{
    double Deg = distance * 360 / wheelCir;
    yTargetDistance = distance;
    int Dir = (Deg - getYDeg()) > 1 ? 1 : -1;
    velocity = abs(velocity) * Dir;

    bool done;
    while (!done)
    {
        if (Dir > 0 ? getYDeg() < Deg
                    : getYDeg() >
                          Deg) // todo subract overshot/last triangle to end on distance rather than stop at distance
        {                      // y not past abs target
            rampY.request(velocity);
            done = false;
        }
        else
        {
            done = true;
            rampY.request(0);
            // todo wait in loop for drive to settle
        }
    }
    if (endWait >= 0)
    { // default; set stop, wait for stop, wait for endwait;
        wait(endWait, 0, 1000, true, false, false);
    }
    else
    { // stop no wait; junction/running another drive movement dont worry about waiting for the drive to stop
    }
}
void Drive::moveX(double distance, double velocity, int timeout, int endWait)
{
    double Deg = distance * 360 / wheelCir;
    xTargetDistance = distance;
    int Dir = (Deg - getXDeg()) > 1 ? 1 : -1;
    velocity = abs(velocity) * Dir;

    bool done;
    while (!done)
    {
        if (Dir > 0 ? getXDeg() < Deg
                    : getXDeg() >
                          Deg) // todo subract overshot/last triangle to end on distance rather than stop at distance
        {                      // y not past abs target
            rampX.request(velocity);
            done = false;
        }
        else
        {
            done = true;
            rampX.request(0);
            // todo wait in loop for drive to settle
        }
    }
    if (endWait >= 0)
    { // default; set stop, wait for stop, wait for endwait;
        wait(endWait, 0, 1000, false, true, false);
    }
    else
    { // stop no wait; junction/running another drive movement dont worry about waiting for the drive to stop
    }
}
void Drive::moveZ(double distance, double velocity, int timeout, int endWait)
{
    double Deg = distance;
    zTargetDistance = distance;
    int Dir = (Deg - getZDeg()) > 1 ? 1 : -1;
    velocity = abs(velocity) * Dir;

    bool done;
    while (!done)
    {
        if (Dir > 0 ? getZDeg() < Deg
                    : getZDeg() >
                          Deg) // todo subract overshot/last triangle to end on distance rather than stop at distance
        {                      // y not past abs target
            rampZ.request(velocity);
            done = false;
        }
        else
        {
            done = true;
            rampZ.request(0);
            // todo wait in loop for drive to settle
        }
    }
    if (endWait >= 0)
    { // default; set stop, wait for stop, wait for endwait;
        wait(endWait, 0, 1000, false, false, true);
    }
    else
    { // stop no wait; junction/running another drive movement dont worry about waiting for the drive to stop
    }
}