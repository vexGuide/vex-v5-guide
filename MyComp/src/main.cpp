//Author: Evan Hess
//Date: 8/20/19 (mm/dd/yy)
//Name: MyComp

#include "vex.h"
using namespace vex;

//global objects
brain Brain = brain();
competition Competition = competition();
controller Driver = controller();
motor left = motor(PORT1);
motor right = motor(PORT6);
motor arm = motor(PORT11);

void pre_auton(void) {

}

void autonomous(void) {

}

void usercontrol(void) {
  arm.setVelocity(75, velocityUnits::pct); //you can set the speed (first argument) to whatever you want, it’s a percentage
  left.setVelocity(Driver.Axis3.position(percentUnits::pct), velocityUnits::pct); //set the speed of the left motor to the left y axis position
  
  while(true) {
    left.spin(directionType::fwd); //set the direction forward when the joystick is pushed
    
    right.spin(directionType::fwd, Driver.Axis4.position(percentUnits::pct), velocityUnits::pct); //or do it all in one step, this time on the right y axis

    if(Driver.ButtonUp.pressing()) { //this function returns a bool which, as we know, can be true or false
      arm.spin(directionType::fwd); //we already defined the speed before the while loop
    }
    else if(Driver.ButtonDown.pressing()) { //the opposite of the last if block
      arm.spin(directionType::rev); //spin the REVerse way
    }
    else { //if either of those two buttons are not pressed
      arm.stop(); //stop. easy enough
    }
  }
}

int main(void) {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while(true) {
    task::sleep(100);
  }
}