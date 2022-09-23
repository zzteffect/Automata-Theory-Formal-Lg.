#include <stdarg.h>

#ifndef _TRANSITIONS_H
#define _TRANSITIONS_H
#include <iostream>
#include <fstream>
using namespace std;
class Transition;

#ifndef _STATE_H
#include "State.h"
#endif

class Transition {
   private:
      State *currState;//current state
      char symbol; //symbol to read in transition {0..9}/{a..z}->regex?
      State *nextState;//point to next state
      bool processed = false;//haven't been processed
      
   public:
      Transition();
      Transition(State &curr, char symbol, State &next);
      Transition(const Transition &t1);
      Transition& operator=(const Transition &rhs);
   
      char getSymbol(){return symbol;}
      State *getCurrState(){return currState;}
      State *getNextState(){return nextState;}
      void setProcessed(){processed = true;}
      bool processedStatus(){return processed;}
      void getInfo();
     };

#endif // _TRANSITION_H