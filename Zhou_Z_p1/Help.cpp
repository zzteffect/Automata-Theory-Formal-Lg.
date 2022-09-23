#include "Help.h"
using namespace std;

Help::Help(){
    inputFileName = "";  
}

void Help::input(string fileName){
    string line;
    fstream inputFile(fileName);
    string operation;//state or transition
    int s1;
    string s2;

    string symbol;
    int p, q;
    Transition t1;

    if(!inputFile.is_open()){
               cout << "No such file" << endl;
            }else{
               while(!inputFile.eof()){
                     getline(inputFile, line);
                     Parser l(line);
                     if (line == "") {
                        if (cin.fail())
                        break;
                        continue;
                        }
                        operation = l.getOperation();
                        if(operation == "state"){
                            s1 = stoi(l.getArg1());
                            s2 = l.getArg2();
                            nfa.setState(s2, s1);
                        }

                        if(operation == "transition"){
                            p = stoi(l.getArg1());
                            symbol = l.getArg2();
                            q = stoi(l.getArg3());

                            if(nfa.isNewState(p)){
                                nfa.setState("trans", p);
                            }else if(nfa.isNewState(q)){
                                nfa.setState("trans", q);
                            }
                            t1 = nfa.makeTransition(p, symbol[0], q);
                        }
               }
            }
        inputFile.close();
}

void Help::info(){
    nfa.StateLists();
}

void Help::processString(string inputS, ofstream& newFile){
    nfa.processString(inputS, newFile);
}