//Jennifer Khuu, jtk2eh, 2/6/20
//File testPostfixCalc.cpp

#include <iostream>
#include "postfixCalculator.h"
#include "stack.h"
#include <cstdlib>
//#include <stack>

class postfixCalculator;

int main(){
  /* postfixCalculator p;
   p.push(5);
  p.push(6);
  p.add();
  p.push(15);
  p.subtract();
  p.push(-4);
  p.divide();
  p.push(3);
  p.multiply();
  cout << "Result is: " << p.top() << endl;
  return 0;*/
  postfixCalculator p;
  string s;
  while(cin >> s) {
     if(s=="+"){
       p.add();
     }
     else if(s=="-"){
       p.subtract();
     }
     else if(s=="*"){
       p.multiply();
     }
     else if(s=="/"){
       p.divide();
     }
     else if(s=="~"){
       p.negate();
     }
     else{
       p.push(atoi(s.c_str()));
     }
   }
  cout<<"Results is: "<<p.top()<<endl;
  return 0;
}
