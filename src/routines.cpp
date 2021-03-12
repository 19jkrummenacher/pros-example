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

  void auton2()
  {
    //right corner
    feed::setAutoFeed(false);
    intake::intakeOut();
    drive::auton::drive(25, 600, 350);
    intake::intakeIn();
    feed::setAutoFeed(false);

    //right middle
  }
}
