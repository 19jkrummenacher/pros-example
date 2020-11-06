#pragma once
#include "main.h"
#include "tarvis/api.hpp"
class Drive : public tarvis::System
{
  public:
    static Drive &get();
    void moveY(double distance, double velocity, int timeout = 1000, int endWait = 100);
    bool isSettled(int v);
    double getXPos();
    double getYPos();
    double getZPos();

  private:
    Drive();
    const double wheelCir = 12.56;
    MotorGroup front_left_wheel{{1, 2}};
    MotorGroup front_right_wheel{{2, 3}};
    MotorGroup back_left_wheel{{4, 5}};
    MotorGroup back_right_wheel{{6, 7}};
    tarvis::Trapezoidal rampY{5, 10, 1, 1, [&](double output) { front_left_wheel.moveVelocity(output); }};
    tarvis::Trapezoidal rampX{5, 10, 1, 1, [&](double output) { front_left_wheel.moveVelocity(output); }};
    tarvis::Trapezoidal rampZ{5, 10, 1, 1, [&](double output) { front_left_wheel.moveVelocity(output); }};

    void userCallstack() override;
    void userInit() override;
    void userDeInit() override;

    void autonCallstack() override;
    void autonInit() override;
    void autonDeInit() override;
};
extern Drive &drive;

// void t() { drive.userCallstack(); }