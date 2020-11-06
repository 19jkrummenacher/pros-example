#pragma once
#include "main.h"
#include "tarvis/api.hpp"
class Feed : public tarvis::System
{
  public:
    static Feed &get();
    void moveY(double distance, double velocity, int timeout = 1000, int endWait = 100);

  private:
    Feed();
    MotorGroup motors{{6, 7}};

    void userCallstack() override;
    void userInit() override;
    void userDeInit() override;

    void autonCallstack() override;
    void autonInit() override;
    void autonDeInit() override;
};
extern Feed &drive;

// void t() { drive.userCallstack(); }