#pragma once
#include "main.h"
#include "tarvis/api.hpp"
class Drive : public tarvis::System
{
  public:
    static Drive &get();
    void moveY(double distance, double velocity, int timeout = 1000, int endWait = 100);
    void moveX(double distance, double velocity, int timeout = 1000, int endWait = 100);
    void moveZ(double distance, double velocity, int timeout = 1000, int endWait = 100);
    bool isSettled(int v);
    double getXDeg();
    double getYDeg();
    double getZDeg();

  private:
    Drive();
    double yTargetDistance{0};
    double xTargetDistance{0};
    double zTargetDistance{0};
    const double wheelCir = 12.56;
    MotorGroup front_left_wheel{{1, 2}};
    MotorGroup front_right_wheel{{2, 3}};
    MotorGroup back_left_wheel{{4, 5}};
    MotorGroup back_right_wheel{{6, 7}};
    tarvis::Trapezoidal rampY{5, 10, 200, -200, [&](double output) {}};
    tarvis::Trapezoidal rampX{5, 10, 200, -200, [&](double output) {}};
    tarvis::Trapezoidal rampZ{5, 10, 200, -200, [&](double output) {
                                  front_left_wheel.moveVelocity(rampY.output() + rampX.output() + rampZ.output());
                                  front_right_wheel.moveVelocity(rampY.output() - rampX.output() - rampZ.output());
                                  back_left_wheel.moveVelocity(rampY.output() - rampX.output() + rampZ.output());
                                  back_right_wheel.moveVelocity(rampY.output() + rampX.output() - rampZ.output());
                              }};

    void userCallstack() override;
    void userInit() override;
    void userDeInit() override;

    void autonCallstack() override;
    void autonInit() override;
    void autonDeInit() override;
    void wait(int endWait, double vSettled, int timeout, bool y, bool x, bool z);
    const double length = 15; // front to back wheels measured from axil to axil
    const double width =
        15; // left to right wheels measured from the left of the left wheel to the left of the right wheel
};
extern Drive &drive;

// void t() { drive.userCallstack(); }