#include "hardware.hpp"
okapi::Controller controllerMaster(okapi::ControllerId::master);
namespace drive
{
    okapi::MotorGroup front_left_motor{
        {okapi::Motor(4, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(3, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup front_right_motor{
        {okapi::Motor(2, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(1, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup back_left_motor{
        {okapi::Motor(14, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(13, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};
    okapi::MotorGroup back_right_motor{
        {okapi::Motor(12, false, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(11, true, okapi::AbstractMotor::gearset::green, okapi::Motor::encoderUnits::degrees)}};

    okapi::ControllerButton btnBrake = controllerMaster[okapi::ControllerDigital::B];

    Ramping LeftN(2, 10, 200, -200);
    Ramping RightN(2, 10, 200, -200);
    Ramping LeftS(2, 10, 200, -200);
    Ramping RightS(2, 10, 200, -200);
} // namespace drive

namespace intake
{
    okapi::MotorGroup motors{
        {okapi::Motor(6, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(16, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::R2];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::R1];

} // namespace intake
namespace feed
{
    okapi::MotorGroup motors{
        {okapi::Motor(10, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(20, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::L2];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::L1];

} // namespace feed