#pragma once
#include "okapi/api.hpp"
#include "ramping.hpp"
extern okapi::Controller controllerMaster;
extern pros::Controller controllerSlave;

namespace drive
{
    extern okapi::MotorGroup front_left_motor;
    extern okapi::MotorGroup front_right_motor;
    extern okapi::MotorGroup back_left_motor;
    extern okapi::MotorGroup back_right_motor;
    extern okapi::ControllerButton btnBrake;

    extern Ramping LeftN;
    extern Ramping RightN;
    extern Ramping LeftS;
    extern Ramping RightS;

} // namespace drive

namespace intake
{
    extern okapi::MotorGroup motors;
    extern okapi::ControllerButton btnUp;
    extern okapi::ControllerButton btnDown;
    extern okapi::ControllerButton btnDownArrow;
    extern okapi::ControllerButton btnY;

} // namespace intake
namespace feed
{
    extern okapi::Motor frontFeed;
    extern okapi::Motor backFeed;
    extern okapi::ControllerButton btnRightArrow;
    extern okapi::ControllerButton btnY;
    extern okapi::ControllerButton btnB;
    extern okapi::ControllerButton btnUp;
    extern okapi::ControllerButton btnDownArrow;
    extern okapi::ControllerButton btnDown;
    extern okapi::ControllerButton btnRDown;
    extern okapi::ControllerButton btnRUp;
    extern pros::Optical frontOpt;
    extern pros::Optical backOpt;
} // namespace feed
