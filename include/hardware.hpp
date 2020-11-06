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

} // namespace intake
namespace feed
{
    extern okapi::MotorGroup motors;
    extern okapi::ControllerButton btnUp;
    extern okapi::ControllerButton btnDown;

} // namespace feed