#include "feed.hpp"
namespace feed
{
<<<<<<< HEAD
  bool autoFeedToggle = false;
  double redValue = 20;
  double blueValue = 320;

  /**
  * Universal methods for feed motors
  *
  */
  void outChute()
  {
    backFeed.moveVoltage(12000);
    frontFeed.moveVoltage(-12000);
    topFeed.moveVoltage(0);
  }

  void feedOut()
  {
    backFeed.moveVoltage(6000);
    frontFeed.moveVoltage(6000);
    topFeed.moveVoltage(6000);
  }

  void feedIn()
  {
    frontFeed.moveVoltage(-12000);
    backFeed.moveVoltage(-12000);
    topFeed.moveVoltage(0);
  }

  void fire()
  {
    frontFeed.moveVoltage(-12000);
    topFeed.moveVoltage(-12000);
    backFeed.moveVoltage(-12000);
  }

  void feedFront()
  {
    frontFeed.moveVoltage(12000);
    topFeed.moveVoltage(0);
    backFeed.moveVoltage(0);
  }

  void stopFeed()
  {
    backFeed.moveVoltage(0);
    frontFeed.moveVoltage(0);
    topFeed.moveVoltage(0);
  }

  void customFeedSpeed(int voltage)
  {
    backFeed.moveVoltage(voltage);
    frontFeed.moveVoltage(voltage);
    topFeed.moveVoltage(voltage);
  }

  /**
  * @version 1.0
  * @Date 2/16/2021
  * uses the controller input to control the feed.
  */
  namespace control
  {
    void user()
    {
        if(!autoFeedToggle)
        {
          if (btnUp.changedToPressed() || btnDownArrow.changedToPressed())
          {//move all rollers so the ball goes down
              feedOut();
          }
          else if (btnDown.changedToPressed() || btnRUp.changedToPressed() || btnRDown.changedToPressed())
          {//move all rollers so the ball goes up.
              feedIn();
          }
          else if(btnY.changedToPressed())
          {//move just the bottom rollers.
            fire();
          }
          else if(btnB.changedToPressed())
          {
            feedFront();
          }
          else if(btnRightArrow.changedToPressed())
          {//out chutting
            outChute();
          }
          else if (btnUp.changedToReleased() || btnDown.changedToReleased() || btnY.changedToReleased() || btnB.changedToReleased() || btnRightArrow.changedToReleased() || btnDownArrow.changedToReleased() || btnRUp.changedToReleased() || btnRDown.changedToReleased())
          {
              stopFeed();
          }
        }
        else
        {
          auton::autoFeed();
        }
    }
  }

  /**
  * @version 1.0
  * @Date 2/16/2021
  * autonomously controls the feed.
  */
  namespace auton
  {
    int* getFeedValues()
    {
      int* feedValues = new int[5];
      feedValues[0] = frontOptical.enable_gesture();
      feedValues[1] = backOptical.enable_gesture();
      feedValues[2] = topLineTracker.get_value();
      feedValues[3] = midLineTracker.get_value();
      feedValues[4] = bottomLineTracker.get_value();
      return feedValues;
    }

    void autoFeed()
    {
      if(frontOptical.get_hue() < redValue)
      {
        feedIn();
      }
      else if(frontOptical.get_hue() > blueValue)
      {
        outChute();
      }
      else
      {

      }
    }

    void autoFeedInTime(int milliSecond)
    {
      feedIn();
      pros::delay(milliSecond);
    }
  }
} // namespace feed
=======
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
} // namespace feed
>>>>>>> parent of 18a6ff6... updating
