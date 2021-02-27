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
          if (btnUp.isPressed() || btnRightArrow.isPressed())
          {//intake ball in.
              motors.moveVoltage(12000);
              //intakeOpen = false;
              //motors.setBrakeMode(AbstractMotor::brakeMode::coast);
          }
          else if (btnDown.isPressed() || btnDownArrow.isPressed())
          {//opens intake up
              //targetEncoder = motors.getPosition() + 10;
              motors.moveVoltage(-6000);
              //intakeOpen = true;
              //motors.setBrakeMode((AbstractMotor::brakeMode::hold));
          }
          else if(btnB.isPressed())
          {
            motors.moveVoltage(-12000);
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
      int intakeTarget = 0;
      bool intakeOpen = false;

      /**
      * returns an char depending on if the color sensor can see a red, blue, or nothing. -1 is blue, 0 is nothing, and 1 is red.
      */
      char getColor()
      {
        return 0;//implementation needed.
      }

      /**
      * returns the distance from the sensor.
      */
      char getDistance()
      {
        return 0; //implemenation needed.
      }

      /**
      * returns true if the intake is open.
      */
      bool isIntakeOpen()
      {
        return intakeOpen;
      }

      /**
      * opens intake and keeps it open
      */
      void openIntake()
      {
        intakeOpen = true;
        //implementation needed.
      }

      /**
      * opens intake for selected number of miliseconds
      */
      void openIntake(int miliSeconds)
      {
        intakeOpen = true;
        //implementation needed
      }

      /**
      * only closes intake
      */
      void closeIntake()
      {
        intakeOpen = false;
        //implementation needed
      }

      /**
      * closes intake and runs it continuelsy
      */
      void runIntake()
      {
        intakeOpen = false;
        //implementation needed
      }

      /**
      * closes intake and runs for a specified number of miliSeconds.
      */
      void runIntake(int miliSeconds)
      {
        intakeOpen = false;
        //implementation needed
      }

      /**
      * cuts the power to the intakes and closes them
      */
      void stopIntake()
      {
        motors.moveVoltage(0);
      }

    }
}
