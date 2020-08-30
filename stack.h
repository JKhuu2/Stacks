//Jennifer Khuu, jtk2eh, 2/6/20
//File stack.h

#ifndef STACK_H
#define STACK_H

#include "List.h"
#include <iostream>
using namespace std;

class stack{
 public:
  stack();
  ~stack();
  void push(int x);
  int top();
  void pop();
  bool empty();
 private:
  List* stk;
  int count;
};
#endif
