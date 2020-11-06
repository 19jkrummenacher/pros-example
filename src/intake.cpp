#include "intake.hpp"
Intake &intake = Intake::get();
Intake &Intake::get()
{
    static Intake instance = Intake();
    return instance;
}
Intake::Intake()
{
    motors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

    motors.setEncoderUnits(AbstractMotor::encoderUnits::degrees);

    motors.setGearing(AbstractMotor::gearset::green);

    motors.tarePosition();
}
void Intake::autonCallstack() {}
void Intake::autonInit() { userDeInit(); }
void Intake::autonDeInit() {}

void Intake::userCallstack() {}
void Intake::userInit() { autonDeInit(); }
void Intake::userDeInit() {}