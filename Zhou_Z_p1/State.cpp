#include "State.h"
using namespace std;

State::State(){
    stateType = ""; //defines type of state --> 0-initial, 1-intermediate or 2-final
    X = -1;
    totalT = 0; //transition number
}


State::State(const State &s1){
    stateType = s1.stateType;
    X = s1.X;
    totalT = s1.totalT;
    setOfT.clear();
    for(int i = 0; i < s1.setOfT.size(); i++){
        setOfT.push_back(s1.setOfT[i]);
    }
}
State::State(const string &sType, const int &x){
    stateType = sType;
    X = x;
}

State& State::operator=(const State &rhs){
    //error
    stateType = rhs.stateType;
    X = rhs.X;
    totalT = rhs.totalT;
    setOfT.clear();
    for(int i = 0; i < rhs.totalT; i++){
        setOfT.push_back(rhs.setOfT[i]);
    }
    return *this;
}

void State::setStateType(string sType){
    stateType = sType;
}

string State::getStateType(){
    return stateType;
}

void State::setOrderNum(int num){
    X = num;
}

int State::getOrderNum(){
    return X;
}

void State::addTransition(Transition t){
    setOfT.push_back(t);
    totalT++;
}

Transition State::getTransition(char sym){
    Transition tmp = Transition();
    for(int i = 0; i < setOfT.size(); i++){
        if(setOfT[i].getSymbol() == sym){
            tmp = setOfT[i];
        }
    }
    return tmp;
 }

void State::getSymbolList(){
    for(int i = 0; i<setOfT.size(); i++ ){
        cout<< setOfT[i].getSymbol()<<endl;
    }
}

bool State::hasTransition(char c){
    for(int i = 0; i < setOfT.size(); i++){
        if(setOfT[i].getSymbol() == c){
            return true;
        }
    }
    return false;
}

vector<Transition> State::process( char c){
    vector<Transition> temp;
    for(int i = 0; i < setOfT.size(); i++){
        if(setOfT[i].getSymbol() == c){
            temp.push_back(setOfT[i]);
        }
    }
    return temp;
}

void State::getTInfo(){
    cout<< "Transition num in State "<<totalT<<endl;
    cout<<"size "<< setOfT.size()<<endl;
    for(int i = 0; i < setOfT.size(); i++){
        setOfT[i].getInfo();
    }
}