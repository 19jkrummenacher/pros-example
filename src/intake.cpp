#include "intake.hpp"
namespace intake
{
    void user()
    {
        if (btnUp.changedToPressed())
        {
            motors.moveVoltage(
                12000); // maximum voltage AKA maximum power; velocities will verry but that shouldnt matter as the
                        // intake just needs to intake a ball as fast as posible, not at a consitent speed
        }
        else if (btnDown.changedToPressed())
        {
            motors.moveVelocity(
                -100); // intake the ball down at a const velocity as to make it consitent so the driver
                       // knows what to expect when things go wrong, better allowing them to focus on how to
                       // make up time/mini panic and not have to worry/think as hard about how to correct it
        }
        else if (btnUp.changedToReleased() || btnDown.changedToReleased()) //"||" means or
        {
            motors.moveVelocity(0); // stop motors
        }
    }
} // namespace intake