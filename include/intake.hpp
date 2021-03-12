#pragma once
#include "main.h"
namespace intake
{
  void intakeIn();
  void intakeOutHalfSpeed();
  void intakeOut();
  void stopIntake();
  namespace control
  {
    void user();
  }

  namespace auton
  {
    void execute();
    void autoIntakeOpen(bool, int);
  }


} // namespace intake
