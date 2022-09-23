#ifndef _NFA_H
#define _NFA_H
#include <iostream>
#include <fstream>
#include <vector>
#include "State.h"
#include "Transition.h"

using namespace std;

class NFA {
   private:
      int numOfStatesUsed;
      int unused;
      State empty;
      vector<State> setOfStates;

      int numOfTransitions;
      vector<Transition> setOfTransitions;
    
   public:
      NFA();
      int getNumOfStates(){return numOfStatesUsed;}
      int getUnused(){return unused;}
      void setState(string type, int X);
      State getState(int X);

      int getNumOfTransitions(){return numOfTransitions;}
      Transition makeTransition(int c, char s, int n);
      void getTransitionInfo(State curr);

      bool isNewState(int cNum);
      void StateLists();

      int processString(string s, ofstream& newFile);

      bool Exist(vector<int> temp, int stateX);
      int Result(vector<int> temp, string r, ofstream& newFile);
     };
#endif // _NFA_H