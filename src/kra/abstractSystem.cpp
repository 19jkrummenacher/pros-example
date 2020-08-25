#include "kra/abstractSystem.hpp"
namespace kra
{
    AbstractSystem::AbstractSystem(okapi::MotorGroup motors, okapi::AbstractMotor::gearset gearset,
                                   okapi::AbstractMotor::encoderUnits encoderUnits,
                                   okapi::AbstractMotor::brakeMode breakMode)
        : okapi::MotorGroup(motors)
    {
        motors.setGearing(gearset);
        motors.setEncoderUnits(encoderUnits);
        motors.setBrakeMode(breakMode);
    }
} // namespace kra