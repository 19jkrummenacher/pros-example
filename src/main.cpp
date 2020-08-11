#include "main.h"
//todo spell check comments
//controllers
Controller con(ControllerId::master);
//drive
ControllerButton driveBtnHold = ControllerButton(ControllerId::master, ControllerDigital::R2);
Motor driveMtrLF(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor driveMtrLB(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor driveMtrRF(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor driveMtrRB(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
// Motor driveLF(1,false,AbstractMotor::gearset::green,AbstractMotor::encoderUnits::degrees);
//intake
ControllerButton intakeBtnUp = ControllerButton(ControllerId::master, ControllerDigital::R2);
ControllerButton intakeBtnDown = ControllerButton(ControllerId::master, ControllerDigital::A);
Motor intakeMtr(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
//feed
ControllerButton feedBtnUp = ControllerButton(ControllerId::master, ControllerDigital::L1);
ControllerButton feedBtnDown = ControllerButton(ControllerId::master, ControllerDigital::L2);
Motor feedMtr(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
//outtake
ControllerButton outtakeBtnUp = ControllerButton(ControllerId::master, ControllerDigital::R1);
ControllerButton outtakeBtnDown = ControllerButton(ControllerId::master, ControllerDigital::B);
Motor outtakeMtr(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

void driveExecute()
{
	//joystick deadbanding; removes joystick drift
	double joyLY{deadband(con.getAnalog(ControllerAnalog::leftY), -10.0/200,10.0/200)};
	double joyLX{deadband(con.getAnalog(ControllerAnalog::leftX), -10.0/200,10.0/200)};
	double joyRY{deadband(con.getAnalog(ControllerAnalog::rightY), -10.0/200,10.0/200)};
	double joyRX{deadband(con.getAnalog(ControllerAnalog::rightX), -10.0/200,10.0/200)};

	//convert to robot velocities "arcade";
	double x, y, z;
	x = joyLX + joyRX / 2; //sideways[-1,1]
	y = joyLY + joyRY / 2; //forwards[-1,1]
	z = joyRY - y;		   //turning[-1,1]

	//deadband x
	x = deadband(x, static_cast<float>(-50) / 200,static_cast<float>(50)/200); //50 is being cast to a float as otherwise the compiler would implicitly recogognize it as a int 50 / int 200 = 0 (50/200=0.25 however int/int=int therefor 0.25 has an integer value of 0); one could also just write 50.0/200 implicitly making the var types "float/int=float"; see joystick deadbanding

	//stuff like manipulating z's magnitude AKA "turning speed"
	// double maxTurnSpeed = 0.5;
	// z = remapRange(z, -1, 1, -maxTurnSpeed, maxTurnSpeed);

	//convert to motor velocies from robot velocies & update the motor target velocities
	driveMtrLF.moveVelocity((y + x + z) * 200);
	driveMtrLB.moveVelocity((y - x + z) * 200);
	driveMtrRF.moveVelocity((y - x - z) * 200);
	driveMtrRB.moveVelocity((y + x - z) * 200);

	if (driveBtnHold.changedToPressed()) //changedToPressed should work, but if not just do a toggling if
	{
		//todo show the equivalent using if, else if, else statement block
		switch (driveMtrLF.getBrakeMode()) //think of it a bunch of if statements, these are useful for enums AKA enumerations.
		{
		case AbstractMotor::brakeMode::hold: //if("driveMtrLF.getBrakeMode()"="AbstractMotor::brakeMode::hold")then execute the below
			driveMtrLF.setBrakeMode(AbstractMotor::brakeMode::coast);
			driveMtrLB.setBrakeMode(AbstractMotor::brakeMode::coast);
			driveMtrRF.setBrakeMode(AbstractMotor::brakeMode::coast);
			driveMtrRB.setBrakeMode(AbstractMotor::brakeMode::coast);
			break;							  //break out of the switch statement (AKA jump to where it says "switch breaks to here")
		case AbstractMotor::brakeMode::coast: //if("driveMtrLF.getBrakeMode()"="AbstractMotor::brakeMode::coast")then execute the below
			driveMtrLF.setBrakeMode(AbstractMotor::brakeMode::hold);
			driveMtrLB.setBrakeMode(AbstractMotor::brakeMode::hold);
			driveMtrRF.setBrakeMode(AbstractMotor::brakeMode::hold);
			driveMtrRB.setBrakeMode(AbstractMotor::brakeMode::hold);
			break; //break out of the switch statement (AKA jump to where it says "switch breaks to here")
		default:
			break;
		}
		//switch breaks to here
	}
}

	//todo verify okapilib 4 got changed+... methods working

	//use some kind of a toggle when to reduce spaming move commands to a motor. this way if you want to add a motorControl layter on that need to move the motor you dont have to figure out how to stop all previous motorControls from spaming to the motor. makes it easy for "last pressed/motorControl takes priority"
	//that ideoligy should be applied to all hardware. with hardware dont be a stripper, in software dont be a spammer, unless needed
void intakeExecute()
{
	if (intakeBtnUp.changedToPressed())
	{
		intakeMtr.moveVoltage(12000); //maximum voltage AKA maximum power; velocities will verry but that shouldnt matter as the intake just needs to intake a ball as fast as posible, not at a consitent speed
	}
	else if (intakeBtnDown.changedToPressed())
	{
		intakeMtr.moveVelocity(-100); //intake the ball down at a const velocity as to make it consitent so the driver knows what to expect when things go wrong, better allowing them to focus on how to make up time/mini panic and not have to worry/think as hard about how to correct it
	}
	else if (intakeBtnUp.changedToReleased() || intakeBtnDown.changedToReleased()) //"||" means or
	{
		intakeMtr.moveVelocity(0); //stop motor
	}
}
void feedExecute()
{
	if (feedBtnUp.changedToPressed())
	{
		feedMtr.moveVelocity(200); //this doesnt need to be "as fast as posible" having the timing be more consistent feeling has a more priority
	}
	else if (feedBtnDown.changedToPressed())
	{
		feedMtr.moveVelocity(-100);
	}
	else if (feedBtnUp.changedToReleased() || feedBtnDown.changedToReleased()) //"||" means or
	{
		feedMtr.moveVelocity(0); //stop motor
	}
}
void outtakeExecute()
{
	if (outtakeBtnUp.changedToPressed())
	{
		outtakeMtr.moveVelocity(200); //this doesnt need to be "as fast as posible" having the timing be more consistent feeling has a more priority
	}
	else if (outtakeBtnDown.changedToPressed())
	{
		outtakeMtr.moveVelocity(-100);
	}
	else if (outtakeBtnUp.changedToReleased() || outtakeBtnDown.changedToReleased()) //"||" means or
	{
		outtakeMtr.moveVelocity(0); //stop motor
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	while (true)
	{
		driveExecute();
		intakeExecute();
		feedExecute();
		outtakeExecute();
		pros::delay(20);//the maximum refresh of the motors is 20_ms, so might as well save some battery
	}
}