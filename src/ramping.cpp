#include "ramping.hpp"
#include "drive.hpp"

namespace ramping
{
  double ramping(MotorGroup motors, double requestedVel)
  {
    int rateOfChange = 100;
    if(std::abs(requestedVel - motors.getActualVelocity()) > rateOfChange)
    {
        if(requestedVel - motors.getActualVelocity() > 0)
          return motors.getActualVelocity() + rateOfChange;
        else if(requestedVel - motors.getActualVelocity() < 0)
          return motors.getActualVelocity() - rateOfChange;
    }
    else
    {
      return requestedVel;
    }
  }
}
