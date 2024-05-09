#include "vex.h"

/*

FIRST

"Match"
"Skills"

SECOND

"Left"
"Center"
"Right"

THIRD

"Simple"
"Complex"
"Half Winpoint"
"Winpoint"
*/

void pre_auton(){
  Calibrate();

  ms.Assign("Match", "Left", "Winpoint", new auton{
    [](){
      Inertial7.calibrate();
      intake.setVelocity(100,percent);
      intake.spinFor(-45,degrees);
      chassis.drive_with_voltage(-3,-7);
      wait (1.6,sec);
      RVwings.set(true);
      chassis.drive_with_voltage(3,6);
      wait (1,sec);
      chassis.drive_with_voltage(-10,10);
      wait (.3,sec);
      RVwings.set(false);
      chassis.drive_with_voltage(2,-2);
      wait (.71,sec);
      chassis.drive_with_voltage(10,10);
      wait (.25,sec);
      chassis.drive_with_voltage(0,0);
      //changing this value will affect how far it drives forward and how long
      intake.spinFor(-10050,degrees);
    },
      "Basic winpoint"
  });

  ms.Assign("Match", "Right", "Simple", new auton{
    [](){
      Inertial7.calibrate();
      intake.setVelocity(100,percent);
      intake.spinFor(45,degrees,false);
      RHwings.set(true);
      wait (1,sec);
      RHwings.set(false);
      intake.spinFor(4300,degrees,false);
      chassis.drive_with_voltage(10, 10);
      wait (1,sec);
      chassis.drive_distance(0);
      wait (1,sec);
      chassis.drive_with_voltage(4, -4);
      wait (.6,sec);
      RHwings.set(true);
      LHwings.set(true);
      chassis.drive_with_voltage(8, 8);
      wait (.002,sec);
      intake.spinFor(10050,degrees);
      chassis.drive_distance(-7);
    },
      "5 ball"
  });

  ms.SetTestAutonomous("Match", "Left", "Winpoint");
	while(ms.should_update && (Competition.isFieldControl() || Competition.isCompetitionSwitch())){
		ms.Update();
		wait(20, msec);
	}
}