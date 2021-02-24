#include "intake.hpp"
namespace intake
{
<<<<<<< HEAD
  /**
  * @version 1.0
  * @Date 2/16/2021
  * the control namespace is used for storing methods for use during the driving period.
  */
  namespace control
  {
    int targetEncoder = 0;
    bool intakeOpen = false;

    /**
    * user is used for taking in controller reading and controlling the robot in Driver mode.
    * Button R1 intakes in the ball
    * Button R2 opens up the intake.
    * Button DownArrow opens up the intake.
    */
      void user()
      {
          //maybe a manual toggle in the future.
          if (btnUp.changedToPressed() || btnRightArrow.changedToPressed())
          {//intake ball in.
              motors.moveVoltage(12000);
              //intakeOpen = false;
              //motors.setBrakeMode(AbstractMotor::brakeMode::coast);
          }
          else if (btnDown.changedToPressed() || btnDownArrow.changedToPressed())
          {//opens intake up
              //targetEncoder = motors.getPosition() + 10;
              motors.moveVoltage(-6000);
              //intakeOpen = true;
              //motors.setBrakeMode((AbstractMotor::brakeMode::hold));
          }
          else if(btnB.changedToPressed())
          {
            motors.moveVoltage(-12000);
          }
          /*else if(intakeOpen)
          {
            if(targetEncoder <= motors.getPosition());
              //implementation needed.
          }*/
          else if (btnUp.changedToReleased() || btnRightArrow.changedToReleased() || btnDown.changedToReleased() || btnDownArrow.changedToReleased() || btnB.changedToReleased())
          {
              motors.moveVoltage(0); // stop motors
          }

      }
    }
    /**
    * @version 1.0
    * @Date 2/16/2021
    * This namespace is used for autonomous control of the robot.
    */
    namespace auton
=======
    void user()
>>>>>>> parent of 18a6ff6... updating
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