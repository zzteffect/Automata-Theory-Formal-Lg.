#ifndef _HELP_H
#define _HELP_H
#include <iostream>
#include <fstream>
#include "NFA.h"
#include "Parser.h"

using namespace std;

class Help {
   private:
      string inputFileName;
      NFA nfa;
   public:
      Help();
      void input(string fileName);
      void processString(string inputS, ofstream& newFile);
      void info();
};
#endif // _HELP_H