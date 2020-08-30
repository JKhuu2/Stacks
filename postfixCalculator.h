//Jennifer Khuu, jtk2eh, 2/6/20
//File postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
//#include <stack>
#include "stack.h"
using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();
  void push(int e);
  int top();
  void pop();
  bool empty();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
 private:
  stack* stk;
};
#endif
