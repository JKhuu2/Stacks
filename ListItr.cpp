//Jennifer Khuu, jtk2eh, 1/31/20
//File ListItr.cpp

#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr(){
  current=NULL;
}

ListItr::ListItr(ListNode* theNode){
  current=theNode;
}

bool ListItr::isPastEnd() const{
  if (current->previous!=NULL&&current->next==NULL){
    return true;
  }
  return false;
}

bool ListItr::isPastBeginning() const{
  if(current->previous==NULL and current->next!=NULL){
    return true;
  }
  return false;
}

void ListItr::moveForward(){
  if(!isPastEnd()){
    current=current->next;
  }
}

void ListItr::moveBackward(){
  if(!isPastBeginning()){
    current=current-> previous;
  }
}

int ListItr::retrieve() const{
  return current->value;
}



