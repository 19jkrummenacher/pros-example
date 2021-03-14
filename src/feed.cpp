#include "feed.hpp"
/**
* @author Jonathan Krummenacher
* @version 1.0
* @Date 2/16/2021
* The feed class controls the feed of the bot. This class is split into two namespace.
* One for user control and one for autonomous control.
*/
namespace feed
{
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

  void clearChute()
  {
    backFeed.moveVoltage(12000);
    frontFeed.moveVoltage(12000);
    topFeed.moveVoltage(12000);
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

  void feedInHalfSpeed()
  {
    frontFeed.moveVoltage(-8000);
    backFeed.moveVoltage(-8000);
    topFeed.moveVoltage(0);
  }

  void fire()
  {
    topFeed.moveVoltage(-12000);
    frontFeed.moveVoltage(-12000);

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

  void setAutoFeed(bool input)
  {
    autoFeedToggle = input;
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
      if (btnUp.isPressed() || btnDownArrow.isPressed())
      {//move all rollers so the ball goes down
          feedOut();
          autoFeedToggle = false;
      }
      else if (btnDown.isPressed() || btnRUp.isPressed() || btnRDown.isPressed())
      {//move all rollers so the ball goes up.
          feedIn();
          autoFeedToggle = false;
      }
      else if(btnY.isPressed() && btnRightArrow.isPressed())
      {
        backFeed.moveVoltage(12000);
        frontFeed.moveVoltage(-12000);
        topFeed.moveVoltage(-12000);
        autoFeedToggle = false;
      }
      else if(btnY.isPressed())
      {//move just the bottom rollers.
        fire();
        autoFeedToggle = false;
      }
      else if(btnB.isPressed())
      {
        feedFront();
        autoFeedToggle = false;
      }
      else if(btnRightArrow.isPressed())
      {//out chutting
        outChute();
        autoFeedToggle = false;
      }
      else if(btnUpArrow.isPressed())
      {
        autoFeedToggle = !autoFeedToggle;
      }
      else if(autoFeedToggle)
      {
        auton::autoFeed();
      }
      else if (!(btnUp.isPressed() || btnDown.isPressed() || btnY.isPressed() || btnB.isPressed() || btnRightArrow.isPressed() || btnDownArrow.isPressed() || btnRUp.isPressed() || btnRDown.isPressed()))
      {
          stopFeed();
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

    void execute()
    {
      if(autoFeedToggle)
      {
        autoFeed();
      }
    }

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
      if(topLineTracker.get_value() < 2500 /*&& (midLineTracker.get_value() < 2500 || bottomLineTracker.get_value() < 2500)*/)
      {
        stopFeed();

      }
      /*else if(topLineTracker.get_value() < 2500 && (midLineTracker.get_value() > 2500 || bottomLineTracker.get_value() > 2500))
      {
        feedInHalfSpeed();
      }*/
      else
      {
        feedIn();
      }
    }

    void autoFeedInTime(int milliSecond)
    {
      feedIn();
      pros::delay(milliSecond);
    }
  }
} // namespace feed
