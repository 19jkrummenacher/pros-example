#pragma once
#include "main.h"
namespace intake
{

  namespace control
  {
    void user();
  }

  namespace auton
  {
    char getColor();
    char getDistance();
    bool isIntakeOpen();
    void openIntake();
    void openIntake(int miliSeconds);
    void closeIntake();
    void runIntake();
    void runIntake(int miliSeconds);
    void stopIntake();
  }


} // namespace intake
