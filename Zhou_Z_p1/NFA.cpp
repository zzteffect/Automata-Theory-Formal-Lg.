#include "NFA.h"
using namespace std;

NFA::NFA(){
    numOfStatesUsed = 0;
    unused = 1000;
    for (size_t i = 0; i < 1000; i++){
    setOfStates.push_back(empty);
    }

    numOfTransitions = 0;
}

void NFA::setState(string type, int X){
    setOfStates[X].setStateType(type);
    setOfStates[X].setOrderNum(X);
    numOfStatesUsed++;
    unused--;
}

State NFA::getState(int X){
    return setOfStates[X];
}

Transition NFA::makeTransition(int c,char s, int n){
    Transition t;
    t = Transition(setOfStates[c], s, setOfStates[n]);

    setOfStates[c].addTransition(t);  
    setOfTransitions.push_back(t);
    numOfTransitions++;
    return t;
}

 void NFA::getTransitionInfo(State curr){
    cout<<"info:"<< curr.getStateType()<<endl;
 }

bool NFA::isNewState(int cNum){
    if(setOfStates[cNum].getOrderNum() == -1){//haven't been created
        return true;
    }
    return false;
}

void NFA::StateLists(){
    for(int i = 0; i < 1000; i++){
        if(setOfStates[i].getOrderNum() != -1){
            cout<<"State: "<<setOfStates[i].getOrderNum() <<"  Type: "<<setOfStates[i].getStateType() 
                <<" Have Transitions# "<<setOfStates[i].getTransitionNum()<<endl;
        }
    }
}

int NFA::processString(string s, ofstream& newFile){
    int size = s.size(), track = 0;
    State *current;
    vector<Transition> avaT;//available transitions in state
    int num;
    vector<int> accept;
    vector<int> reject;
    bool aj;//accept

    for(int i = 0; i < 1000; i++){
        if(setOfStates[i].getStateType() == "start"){
            current = &setOfStates[i];
        }
    }

    while(size){
        if(current->hasTransition(s[track])){
            avaT = current->process(s[track]);
            num = avaT.size()-1;
                if(avaT[num].processedStatus() == false){
                    if(avaT[num].getNextState()->hasTransition(s[track+1])){
                        current = avaT[num].getNextState();
                        avaT[num].setProcessed();
                        if(current->getStateType() == "accept"){
                           if(!Exist(accept,current->getOrderNum())){
                                accept.push_back(current->getOrderNum());
                           }
                           return Result(accept, "accept", newFile);
                           // aj = true;
                        }
                    }else{
                        aj = false;
                        current = avaT[num].getNextState();
                        if(!Exist(reject,current->getOrderNum())){
                            reject.push_back(current->getOrderNum());
                        }
                        return Result(reject, "reject", newFile);
                    }
                    num--;
            }
            track++;
        }
        size--;
    }
    return -1;
}

bool NFA::Exist(vector<int> temp, int stateX){
    for(int i = 0; i = temp.size(); i++){
        if(temp[i] == stateX){
            return true;
        }
    }
    return false;
}

int NFA::Result(vector<int> temp, string r, ofstream& newFile){
    cout<<r<<" ";
    newFile<<r<<" ";
   // cout<<"size "<<temp.size()<<endl;;
    for(int i = 0; i < temp.size(); i++){
        cout<<temp[i]<<" ";
        newFile<<temp[i]<<" ";
    }
    cout<<endl;
    return -1;
}