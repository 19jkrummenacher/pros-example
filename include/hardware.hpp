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
    extern okapi::ControllerButton BtnIn;
    extern okapi::ControllerButton BtnOut;
    extern okapi::ControllerButton ManualIn;
} // namespace intake
namespace feed
{

    extern okapi::ControllerButton BtnIn;
    extern okapi::ControllerButton BtnOut;
    extern okapi::ControllerButton BtnBack;
    extern okapi::ControllerButton Down;
    extern okapi::ControllerButton UpOnly;
    extern okapi::ControllerButton mid;
    extern okapi::ControllerButton autoElev;

    extern okapi::Motor frontFeed;
    extern okapi::Motor backFeed;
    extern okapi::Motor topFeed;
    extern pros::Optical frontOptical;
    extern pros::Optical backOptical;
    extern pros::ADIAnalogIn topLineTracker;
    extern pros::ADIAnalogIn midLineTracker;
    extern pros::ADIAnalogIn bottomLineTracker;
} // namespace feed
