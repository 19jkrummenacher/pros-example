#pragma once
#include "main.h"
namespace feed
{
  void fire();
  void stopFeed();
  void feedIn();
  void feedInHalfSpeed();
  void outChute();
  void clearChute();
  void setAutoFeed(bool);
  namespace control
  {
    void user();
  }
  namespace auton
  {
    void execute();
    int* getFeedValues();
    void autoFeed();
  }
    // void auton();
} // namespace feed
