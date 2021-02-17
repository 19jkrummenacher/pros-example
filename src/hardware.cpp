#include "hardware.hpp"
okapi::Controller controllerMaster(okapi::ControllerId::master);
namespace drive
{
    okapi::MotorGroup front_left_motor{
        {okapi::Motor(4, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(3, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup back_left_motor{
        {okapi::Motor(2, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(1, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup front_right_motor{
        {okapi::Motor(15, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(14, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup back_right_motor{
        {okapi::Motor(13, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(12, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};

    okapi::ControllerButton btnBrake = controllerMaster[okapi::ControllerDigital::A];

    Ramping LeftN(2, 10, 200, -200);
    Ramping RightN(2, 10, 200, -200);
    Ramping LeftS(2, 10, 200, -200);
    Ramping RightS(2, 10, 200, -200);
} // namespace drive

namespace intake
{
    okapi::MotorGroup motors{
        {okapi::Motor(10, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(20, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::R1];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::R2];
    okapi::ControllerButton btnDownArrow = controllerMaster[okapi::ControllerDigital::down];
    okapi::ControllerButton btnY = controllerMaster[okapi::ControllerDigital::Y];

} // namespace intake
namespace feed
{
    okapi::Motor frontFeed(6, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::Motor backFeed(16, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::L2];
    okapi::ControllerButton btnDownArrow = controllerMaster[okapi::ControllerDigital::down];
    okapi::ControllerButton btnRightArrow = controllerMaster[okapi::ControllerDigital::right];
    okapi::ControllerButton btnY = controllerMaster[okapi::ControllerDigital::Y];
    okapi::ControllerButton btnB = controllerMaster[okapi::ControllerDigital::B];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::L1];
    okapi::ControllerButton btnRUp = controllerMaster[okapi::ControllerDigital::R2];
    okapi::ControllerButton btnRDown = controllerMaster[okapi::ControllerDigital::R1];
    pros::Optical frontOpt(8);
    pros::Optical backOpt(9);

} // namespace feed
