#include "feed.hpp"
Feed &feed = Feed::get();
Feed &Feed::get()
{
    static Feed instance = Feed();
    return instance;
}
Feed::Feed()
{
    motors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

    motors.setEncoderUnits(AbstractMotor::encoderUnits::degrees);

    motors.setGearing(AbstractMotor::gearset::green);

    motors.tarePosition();
}
void Feed::autonCallstack() {}
void Feed::autonInit() { userDeInit(); }
void Feed::autonDeInit() {}

void Feed::userCallstack() {}
void Feed::userInit() { autonDeInit(); }
void Feed::userDeInit() {}