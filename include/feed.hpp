#pragma once
#include "main.h"
namespace feed
{
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
