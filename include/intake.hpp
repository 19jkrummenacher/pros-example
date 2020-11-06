#pragma once
#include "main.h"
#include "tarvis/api.hpp"
class Intake : public tarvis::System
{
  public:
    static Intake &get();

  private:
    Intake();
    MotorGroup motors{{1, 2}};

    void userCallstack() override;
    void userInit() override;
    void userDeInit() override;

    void autonCallstack() override;
    void autonInit() override;
    void autonDeInit() override;
};
extern Intake &intake;