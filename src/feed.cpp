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
  /**
  * @version 1.0
  * @Date 2/16/2021
  * uses the controller input to control the feed.
  */
  namespace control
  {
    void user()
    {
        if (btnUp.changedToPressed() || btnDownArrow.changedToPressed())
        {//move all rollers so the ball goes down
            backFeed.moveVoltage(6000);
            frontFeed.moveVoltage(6000);
        }
        else if (btnDown.changedToPressed())
        {//move all rollers so the ball goes up.
            frontFeed.moveVoltage(-12000);
            backFeed.moveVoltage(-12000);
        }
        else if(btnRightArrow.changedToPressed() || btnRUp.changedToPressed() || btnRDown.changedToPressed())
        {//move just the bottom rollers.
          frontFeed.moveVoltage(-12000);
          backFeed.moveVoltage(-12000);
        }
        else if(btnY.changedToPressed())
        {
          backFeed.moveVoltage(6000);
          frontFeed.moveVoltage(-6000);
        }
        else if (btnUp.changedToReleased() || btnDown.changedToReleased() || btnY.changedToReleased() || btnRightArrow.changedToReleased() || btnDownArrow.changedToReleased() || btnRUp.changedToReleased() || btnRDown.changedToReleased())
        {
            backFeed.moveVoltage(0);
            frontFeed.moveVoltage(0);
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

  }
} // namespace feed
