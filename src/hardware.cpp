#include "hardware.hpp"
#include "main.h"
okapi::Controller controllerMaster(okapi::ControllerId::master);
namespace drive
{
    okapi::MotorGroup front_left_motor{
<<<<<<< HEAD
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

    okapi::ControllerButton btnBrake = controllerMaster[okapi::ControllerDigital::A];
    okapi::ControllerButton btnUpArrow = controllerMaster[okapi::ControllerDigital::up];
=======
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
<<<<<<< HEAD
>>>>>>> parent of 18a6ff6... updating
=======
>>>>>>> parent of 18a6ff6 (updating)

    /*Ramping LeftN(2, 10, 200, -200);
    Ramping RightN(2, 10, 200, -200);
    Ramping LeftS(2, 10, 200, -200);
    Ramping RightS(2, 10, 200, -200);*/
} // namespace drive

namespace intake
{
    okapi::MotorGroup motors{
<<<<<<< HEAD
<<<<<<< HEAD
        {okapi::Motor(10, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(20, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::R1];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::R2];
    okapi::ControllerButton btnB = controllerMaster[okapi::ControllerDigital::B];
    okapi::ControllerButton btnDownArrow = controllerMaster[okapi::ControllerDigital::down];
    okapi::ControllerButton btnRightArrow = controllerMaster[okapi::ControllerDigital::right];
=======
=======
>>>>>>> parent of 18a6ff6 (updating)
        {okapi::Motor(6, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(16, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::R2];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::R1];
<<<<<<< HEAD
>>>>>>> parent of 18a6ff6... updating
=======
>>>>>>> parent of 18a6ff6 (updating)

} // namespace intake
namespace feed
{
<<<<<<< HEAD
<<<<<<< HEAD
    okapi::Motor frontFeed(6, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::Motor backFeed(16, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::Motor topFeed(7, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::L2];
    okapi::ControllerButton btnB = controllerMaster[okapi::ControllerDigital::B];
    okapi::ControllerButton btnDownArrow = controllerMaster[okapi::ControllerDigital::down];
    okapi::ControllerButton btnRightArrow = controllerMaster[okapi::ControllerDigital::right];
    okapi::ControllerButton btnY = controllerMaster[okapi::ControllerDigital::Y];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::L1];
    okapi::ControllerButton btnRUp = controllerMaster[okapi::ControllerDigital::R1];
    okapi::ControllerButton btnRDown = controllerMaster[okapi::ControllerDigital::R2];
    pros::Optical frontOptical(5);
    pros::Optical backOptical(9);

    pros::ADIAnalogIn topLineTracker ('A');
    pros::ADIAnalogIn midLineTracker ('B');
    pros::ADIAnalogIn bottomLineTracker ('C');
=======
    okapi::MotorGroup motors{
        {okapi::Motor(10, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(20, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::L2];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::L1];
>>>>>>> parent of 18a6ff6... updating
=======
    okapi::MotorGroup motors{
        {okapi::Motor(10, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
         okapi::Motor(20, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
    okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::L2];
    okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::L1];
>>>>>>> parent of 18a6ff6 (updating)

} // namespace feed