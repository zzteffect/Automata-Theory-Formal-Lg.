#ifndef _STATE_H
#define _STATE_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class State;

#ifndef __TRANSITIONS_H
#include <vector>
#include "Transition.h"
#endif

class State {
   private:
     string stateType; //defines type of state: start; trans; accept
     int X; // order in state
    int totalT; //transition number
    vector<Transition> setOfT;
   
   public:
      State();
      State(const State &s1);
      State(const string &sType, const int &X);
      State& operator=(const State &rhs);
      void setStateType(string stateType);
      string getStateType();
      void setOrderNum(int num);
      int getOrderNum();

      void addTransition(Transition t);
      int getTransitionNum(){return totalT;}
      Transition getTransition(char symbol);//get tansition location in //char

      void getSymbolList();

      bool hasTransition(char c);

      vector<Transition> process(char c);
      void getTInfo();

      //void hasSymbol(char c);
     };

#endif // _STATE_H