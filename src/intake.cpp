#include "intake.hpp"

/**
* @author Jonathan Krummenacher
* @version 1.0
* @Date 2/16/2021
* The intake class controls the intake of the bot. This class is split into two namespace.
* One for user control and one for autonomous control.
*/
namespace intake
{
  void intakeIn()
  {
    motors.moveVoltage(12000);
  }

  void intakeOutHalfSpeed()
  {
    motors.moveVoltage(-6000);
  }

  void intakeOut()
  {
    motors.moveVoltage(-12000);
  }

  void stopIntake()
  {
    motors.moveVoltage(0);
  }

  void set_brakeMode(okapi::Motor::brakeMode b)
  {
    motors.setBrakeMode(b);
  }

  /**
  * @version 1.0
  * @Date 2/16/2021
  * the control namespace is used for storing methods for use during the driving period.
  */
  namespace control
  {

    /**
    * user is used for taking in controller reading and controlling the robot in Driver mode.
    * Button R1 intakes in the ball
    * Button R2 opens up the intake.
    * Button DownArrow opens up the intake.
    */
      void user()
      {
          //maybe a manual toggle in the future.
          if (btnUp.isPressed() || btnRightArrow.isPressed())
          {//intake ball in.
              intakeIn();
              //intakeOpen = false;
              //motors.setBrakeMode(AbstractMotor::brakeMode::coast);
          }
          else if (btnDown.isPressed() || btnDownArrow.isPressed())
          {//opens intake up
              //targetEncoder = motors.getPosition() + 10;
              intakeOutHalfSpeed();
              //intakeOpen = true;
              //motors.setBrakeMode((AbstractMotor::brakeMode::hold));
          }
          else if(btnB.isPressed())
          {
            intakeOut();
          }
          /*else if(intakeOpen)
          {
            if(targetEncoder <= motors.getPosition());
              //implementation needed.
          }*/
          else if (!(btnUp.isPressed() || btnRightArrow.isPressed() || btnDown.isPressed() || btnDownArrow.isPressed() || btnB.isPressed()))
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
    {
      bool intakeOpen = false;
      bool autoIntakeToggle = false;
      int waitIndex = -1;

      void execute()
      {
        if(autoIntakeToggle)
        {
          if(intakeOpen && motors.getPosition() <= 40)
          {
            intakeOut();
            waitIndex--;
          }
          else if(waitIndex != -1 && waitIndex > 0)
          {
            autoIntakeOpen(false, -1);
          }
          else
          {
              stopIntake();
              waitIndex--;
          }

        }
      }

      void autoIntakeOpen(bool toggle, int wait)
      {
        autoIntakeToggle = toggle;
        waitIndex = wait / 10;
        if(toggle)
        {
          intakeOpen = true;
          motors.tarePosition();
          motors.setBrakeMode(okapi::Motor::brakeMode::brake);
        }
        else
        {
          motors.setBrakeMode(okapi::Motor::brakeMode::coast);
          intakeOpen = false;
          stopIntake();
        }
      }

    }
}
