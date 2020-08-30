//Jennifer Khuu, jtk2eh, 2/6/20
//File stack.cpp

#include "stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

stack::stack(){
  stk=new List();
  count=0;
}

stack::~stack(){
  stk->makeEmpty();
  delete stk;
}

void stack::push(int x){
  stk->insertAtHead(x);
  count++;
}

bool stack::empty(){
  return count<1;
}

void stack::pop(){
    ListItr itr=stk->first();
    stk->remove(itr.retrieve());
    count--;
}

int stack::top(){
  return stk->first().retrieve();
}

