#include <iostream>
#include <string>
#include <fstream>

#include <unistd.h>
#include "Parser.h"
#include "Help.h"
#include "NFA.h"
using namespace std;

int main(int argc , char *argv[]) {
   char opt;
   string myFile, inputS, line;
   Help help;

   if(argc == 3){
     myFile = argv[1];
     inputS = argv[2];
   }else{
     cout << "Invalid Inputs" << endl;
     return -1;
   }
   
    ofstream newFile("output.txt");

    help.input(myFile);
    help.processString(inputS, newFile);
    //help.info();

    newFile.close();
    return 0;
}