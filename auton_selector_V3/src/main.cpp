#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

void usercontrol(void) {
  Calibrate();
}

void autonomous(void) {
  ms.RunAutonomous();
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  printf ("chris for president");

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
