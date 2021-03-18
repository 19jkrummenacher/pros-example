#include "hardware.hpp"
#include "main.h"
okapi::Controller controllerMaster(okapi::ControllerId::master);
namespace drive
{
    okapi::MotorGroup front_left_motor{
        {okapi::Motor(4, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(3, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup back_left_motor{
        {okapi::Motor(2, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(1, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup front_right_motor{
        {okapi::Motor(15, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(14, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup back_right_motor{
        {okapi::Motor(13, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(12, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};

    okapi::ControllerButton btnBrake = controllerMaster[okapi::ControllerDigital::up];

    Ramping LeftN(6, 10, 600, -600);
    Ramping RightN(6, 10, 600, -600);
    Ramping LeftS(6, 10, 600, -600);
    Ramping RightS(6, 10, 600, -600);
} // namespace drive

namespace intake
{
    okapi::MotorGroup motors{
        {okapi::Motor(10, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(20, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
     okapi::ControllerButton BtnIn = controllerMaster[okapi::ControllerDigital::R1];
     okapi::ControllerButton BtnOut = controllerMaster[okapi::ControllerDigital::R2];
     okapi::ControllerButton ManualIn = controllerMaster[okapi::ControllerDigital::X];

} // namespace intake
namespace feed
{
    okapi::Motor frontFeed(6, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::Motor backFeed(16, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::Motor topFeed(7, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    pros::Optical frontOptical(5);
    pros::Optical backOptical(9);
    okapi::ControllerButton BtnIn = controllerMaster[okapi::ControllerDigital::right];
    okapi::ControllerButton BtnOut = controllerMaster[okapi::ControllerDigital::L2];
    okapi::ControllerButton BtnBack = controllerMaster[okapi::ControllerDigital::Y];
    okapi::ControllerButton Down = controllerMaster[okapi::ControllerDigital::down];
    okapi::ControllerButton UpOnly = controllerMaster[okapi::ControllerDigital::B];
    okapi::ControllerButton mid = controllerMaster[okapi::ControllerDigital::A];
    okapi::ControllerButton autoElev = controllerMaster[okapi::ControllerDigital::L1];
    pros::ADIAnalogIn topLineTracker ('A');
    pros::ADIAnalogIn midLineTracker ('B');
    pros::ADIAnalogIn bottomLineTracker ('C');

} // namespace feed
