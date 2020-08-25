#pragma once
#include "okapi/api.hpp"
#include <memory>
namespace kra
{
    class AbstractSystem : public okapi::MotorGroup
    {
      public:
        AbstractSystem(okapi::MotorGroup motors,
                       okapi::AbstractMotor::gearset gearset = okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits encoderUnits = okapi::AbstractMotor::encoderUnits::degrees,
                       okapi::AbstractMotor::brakeMode breakMode = okapi::AbstractMotor::brakeMode::coast);

        virtual void execute() = 0;

        enum States
        {
            UNDEF,  // undefined
            MOVING, // motors are moving
            STOPPED // motors are stoped
        };

      protected:
      private:
    };
} // namespace kra