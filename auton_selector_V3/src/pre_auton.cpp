#include "vex.h"
competition Competition;
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
      
    },
      "Basic winpoint"
  });

  ms.Assign("Match", "Right", "Complex", new auton{
    [](){
      
    },
      "5 ball"
  });

ms.Assign("Match", "Right", "Simple", new auton{
    [](){
      
    },
      "3 ball"
  });

  ms.Assign("Match", "Right", "Half Winpoint", new auton{
    [](){
      
    },
      "4 ball"
  });


  
  ms.SetTestAutonomous("Match", "Left", "Winpoint");
	while(ms.should_update && (Competition.isFieldControl() || Competition.isCompetitionSwitch())){
		ms.Update();
		wait(20, msec);
	}
}