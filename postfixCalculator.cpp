//Jennifer Khuu, jtk2eh, 2/6/20
//File postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"
#include "stack.h"
#include <cstdlib>
//#include <stack>
#include <string>

using namespace std;

postfixCalculator::postfixCalculator(){
  stk=new stack();
 }

void postfixCalculator::push(int e){
  stk->push(e);
}

int postfixCalculator::top(){
  if(!empty()){
    return stk->top();
  }
  cout<< "stack is empty"<<endl;
  exit(-1);
}

void postfixCalculator::pop(){
  if(!empty()){
    stk->pop();
  }
  cout<<"stack is empty"<<endl;
  exit(-1);
}

bool postfixCalculator::empty(){
  return stk->empty();
}

void postfixCalculator::add(){
  int x=stk->top();
  stk->pop();
  int y=stk->top();
  stk->pop();
  stk->push(y+x);
}

void postfixCalculator::subtract(){
  int x=stk->top();
  stk->pop();
  int y=stk->top();
  stk->pop();
  stk->push(y-x);
 }

void postfixCalculator::multiply(){
  int x=stk->top();
  stk->pop();
  int y=stk->top();
  stk->pop();
  stk->push(y*x);
}

void postfixCalculator::divide(){
  int x=stk->top();
  stk->pop();
  int y=stk->top();
  stk->pop();
  stk->push(y/x);
}

void postfixCalculator::negate(){
  int x=stk->top();
  stk->pop();
  x=x*-1;
  stk->push(x);
}


