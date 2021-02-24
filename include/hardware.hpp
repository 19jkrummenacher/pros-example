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
    extern okapi::ControllerButton btnUpArrow;


} // namespace drive

namespace intake
{
    extern okapi::MotorGroup motors;
    extern okapi::ControllerButton btnUp;
    extern okapi::ControllerButton btnDown;
<<<<<<< HEAD
    extern okapi::ControllerButton btnDownArrow;
    extern okapi::ControllerButton btnRightArrow;
    extern okapi::ControllerButton btnB;
=======
>>>>>>> parent of 18a6ff6... updating

} // namespace intake
namespace feed
{
<<<<<<< HEAD
    extern okapi::Motor frontFeed;
    extern okapi::Motor backFeed;
    extern okapi::Motor topFeed;
    extern okapi::ControllerButton btnRightArrow;
    extern okapi::ControllerButton btnY;
    extern okapi::ControllerButton btnUp;
    extern okapi::ControllerButton btnB;
    extern okapi::ControllerButton btnDownArrow;
    extern okapi::ControllerButton btnDown;
    extern okapi::ControllerButton btnRDown;
    extern okapi::ControllerButton btnRUp;
    extern pros::Optical frontOptical;
    extern pros::Optical backOptical;
    extern pros::ADIAnalogIn topLineTracker;
    extern pros::ADIAnalogIn midLineTracker;
    extern pros::ADIAnalogIn bottomLineTracker;
} // namespace feed
=======
    extern okapi::MotorGroup motors;
    extern okapi::ControllerButton btnUp;
    extern okapi::ControllerButton btnDown;

} // namespace feed
>>>>>>> parent of 18a6ff6... updating
