#include "Transition.h"
using namespace std;

Transition::Transition(){
    currState = NULL; //set state pointer as empty
    symbol = '0';
	nextState = NULL;//transitionPointers
}

Transition::Transition(State &curr, char s, State &next){
    currState = &curr;
    symbol = s;
    nextState = &next;
 }

Transition::Transition(const Transition &t1){
    currState = t1.currState;
    symbol = t1.symbol;
    nextState = t1.nextState;
}

Transition& Transition::operator=(const Transition &rhs){
    currState = rhs.currState;
    symbol = rhs.symbol;
    nextState = rhs.nextState;
    return *this;
}

void Transition::getInfo(){
    cout<<"curr state "<< currState->getOrderNum();
    cout<<" symbol "<<symbol;
    cout<<" next state "<< nextState->getOrderNum()<<endl;
}