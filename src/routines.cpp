#include "main.h"
#include "selection.hpp"
#include "feed.hpp"
#include "drive.hpp"
#include "intake.hpp"
#include "routines.hpp"
namespace routines
{

  void auton1()
  {
    //deploy intakes :(, we aren't driving forward because the stops are in the wheel space.
    intake::intakeOut();
    pros::delay(1100);

    //right corner

    feed::setAutoFeed(true);
    //intake::auton::autoIntakeOpen(true, 1000);
    intake::intakeIn();
    drive::auton::drive(32, 500, 350);
    feed::setAutoFeed(false);
    feed::stopFeed();
    drive::auton::drive(-8, 600, 350);
    drive::auton::turnEnc(85, 450, 350);
    feed::setAutoFeed(false);
    intake::auton::autoIntakeOpen(false, -1);
    drive::auton::drive(12, 450, 350);
    drive::auton::driveRecon(300, 500, 0);
    feed::fire();
    intake::intakeIn();
    pros::delay(600);
    intake::stopIntake();
    drive::auton::drive(-31, 600, 350);

    //close middle
    feed::clearChute();
    drive::auton::turnEnc(240, 450, 350);
    feed::setAutoFeed(true);
    intake::auton::autoIntakeOpen(true, 500);
    drive::auton::drive(14, 600, 350);
    drive::auton::turnEnc(-130, 450, 350);
    intake::auton::autoIntakeOpen(true, 1000);
    drive::auton::drive(12,600, 350);
    drive::auton::driveRecon(300, 500, 0);
    feed::setAutoFeed(false);
    feed::fire();
    intake::intakeIn();
    pros::delay(1000);
    feed::setAutoFeed(true);
    drive::auton::drive(-3, 600, 350);
    intake::stopIntake();
    feed::setAutoFeed(false);
    feed::fire();

    //left corner

    drive::auton::turnEnc(125, 450, 350);
    intake::auton::autoIntakeOpen(true, 1000);
    feed::setAutoFeed(true);
    drive::auton::drive(20, 600, 350);
    drive::auton::turnEnc(20, 350, 350);
    intake::auton::autoIntakeOpen(true, 1000);
    drive::auton::drive(20, 600, 350);
    drive::auton::drive(-5, 600, 350);
    drive::auton::turnEnc(-90, 350, 350);


    /*drive::auton::driveRecon(300, 500);
    feed::fire();
    pros::delay(1000);*/

    //right middle
  }

  void auton2()
  {
    feed::fire();
    intake::intakeIn();
    pros::delay(2500);
    /*feed::stopFeed();
    intake::stopIntake();
    drive::auton::drive(-10);
    drive::auton::turnEnc(-120, 200, 200);
    intake::intakeOutHalfSpeed();
    feed::feedIn();
    drive::auton::drive(17);
    intake::intakeIn();
    drive::auton::turnEnc(70, 200, 200);
    feed::stopFeed();
    intake::intakeOutHalfSpeed();
    drive::auton::driveRecon(300, 1500);
    feed::fire();
    pros::delay(1000);
    intake::intakeIn();
    feed::outChute();
    pros::delay(1000);
    drive::auton::drive(-15);*/
  }
}
