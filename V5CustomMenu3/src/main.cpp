/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       JadenZMecham                                              */
/*    Created:      Thu Jan 30 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Potentiometer        pot           A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "auton.h"
#include "driver.h"
#include "menu.h"

using namespace vex;

int Rotation = Potentiometer.value(rotationUnits::deg);
const int Ptotal = 250; // 250 is the max value in degrees read by the potentiometer
const int States = 10; // this is the number of states in the system excluding the idle state
const int n = Ptotal/States; //This is the degrees of the potentiometer divided by the amount of active states

// The above n value gives the range of degrees where you can spin the potentiometer to activate a state. In this case, n will equal 25 degrees
// as 250/10 = 25. There are ten states, meaning that there will be a 25 degree range to be in each state. For the first state, it will be 
// active between 0 and n (25 degrees). The second state is active between n (25 degrees) and 2 * n (50 degrees) and so on. For example,
// let's say that you want 25 states. You would change the "States" value to 25 and the n value becomes 10. This would then mean that each 
// state is activated in a 10 degree range. First state is from 0 to n, the second from n to 2 * n and so on just like before. All you would
// need to do is add more state integers below and add them to the switch case further down. 

//Red States
const int RED1 = 0;
const int RED2 = 1;
const int RED3 = 2;
const int RED4 = 3;

//Blue States
const int BLUE1 = 4;
const int BLUE2 = 5;
const int BLUE3 = 6;
const int BLUE4 = 7;

//Skills States
const int SKILLS1 = 8;
const int SKILLS2 = 9;

//Starting state
const int IDLE = 10;

int currentState = IDLE;


//Prints potentiometer value on the Brain screen
void PrintPotentiometer(){
  Brain.Screen.setFillColor(vex::color::black);
  Brain.Screen.setPenColor(vex::color::white);
  Brain.Screen.printAt(120, 220, "rotation %f degrees", Potentiometer.value(rotationUnits::deg));
}


//Updates the state system using the potentiometer
void Update(){
  Rotation = Potentiometer.value(rotationUnits::deg);
}


//State system which switches between each program
int EvaluateState(int currentstate){
  switch (currentstate){

    case IDLE:
      if (Rotation > 0 && Rotation < n){
        return RED1;
      }
      break;

    case RED1:
      if (Rotation > n && Rotation < 2*n){
        return RED2;
      }
      break;

    case RED2:
      if (Rotation > 2*n && Rotation < 3*n){
        return RED3;
      }
      break;

    case RED3:
      if (Rotation > 3*n && Rotation < 4*n){
        return RED4;
      }
      break;

    case RED4:
      if (Rotation > 4*n && Rotation < 5*n){
        return BLUE1;
      }
      break;

    case BLUE1:
      if (Rotation > 5*n && Rotation < 6*n){
        return BLUE2;
      }
      break;

    case BLUE2:
      if (Rotation > 6*n && Rotation < 7*n){
        return BLUE3;
      }
      break;

    case BLUE3:
      if (Rotation > 7*n && Rotation < 8*n){
        return BLUE4;
      }
      break;

    case BLUE4:
      if (Rotation > 8*n && Rotation < 9*n){
        return SKILLS1;
      }
      break;

    case SKILLS1:
      if (Rotation > 9*n && Rotation < 10*n){
        return SKILLS2;
      }
      break;

  }
  return currentstate;
}


void RED1autonMENU(){

}

void RED2autonMENU(){
  
}

void RED3autonMENU(){
  
}

void RED4autonMENU(){
  
}

void BLUE1autonMENU(){
  
}

void BLUE2autonMENU(){
  
}

void BLUE3autonMENU(){
  
}

void BLUE4autonMENU(){
  
}

void SKILLS1autonMENU(){
  
}

void SKILLS2autonMENU(){
  
}


void ReactToState(){
  if (currentState == RED1){
    RED1autonMENU();
  }

  if (currentState == RED2){
    RED2autonMENU();
  }

  if (currentState == RED3){
    RED3autonMENU();
  }

  if (currentState == RED4){
    RED4autonMENU();
  }

  if (currentState == BLUE1){
    BLUE1autonMENU();
  }

  if (currentState == BLUE2){
    BLUE2autonMENU(); 
  }

  if (currentState == BLUE3){
    BLUE3autonMENU();
  }

  if (currentState == BLUE4){
    BLUE4autonMENU();
  }

  if (currentState == SKILLS1){
    SKILLS1autonMENU();
  }

  if (currentState == SKILLS2){
    SKILLS2autonMENU();
  }
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Update();
  currentState = EvaluateState(currentState);
  ReactToState();

  while (true){
    PrintPotentiometer();
  }
  
}
