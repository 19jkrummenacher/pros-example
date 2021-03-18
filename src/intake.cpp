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
          if()

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
      bool openFirstTime = false;
      int waitIndex = -1;
      int target = -55;

      void execute()
      {
        if(autoIntakeToggle)
        {
          std::cout<<waitIndex<<"\n";

          if(waitIndex != -1 && waitIndex > -100 && waitIndex < 0)
          {
            //autoIntakeOpen(false, 5000);
            intakeOpen = false;
            intakeIn();
            waitIndex--;
          }
          else if(intakeOpen && motors.getPosition() >= target)
          {
            intakeOut();
            waitIndex--;
          }
          else
          {
              stopIntake();
          }

        }
      }

      void autoIntakeOpen(bool toggle, int wait)
      {
        autoIntakeToggle = toggle;
        waitIndex = wait / 10;
        if(openFirstTime)
        {
          target = -120;
          openFirstTime = false;
        }
        else
        {
          target = -55;
        }
        if(toggle)
        {
            intakeOpen = true;
          motors.tarePosition();
          motors.setBrakeMode(okapi::Motor::brakeMode::hold);
        }
        else
        {
          motors.setBrakeMode(okapi::Motor::brakeMode::coast);
          stopIntake();
        }
      }

    }
}
