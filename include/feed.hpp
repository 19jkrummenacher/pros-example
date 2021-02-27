#pragma once
#include "main.h"
namespace feed
{
  void fire();
  namespace control
  {
    void user();
  }
  namespace auton
  {
    int* getFeedValues();
    void autoFeed();
  }
    // void auton();
} // namespace feed
