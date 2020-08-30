//Jennifer Khuu, jtk2eh, 2/6/20
//File List.cpp

#include <iostream>
#include "List.h"
using namespace std;

List::List(){
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
  if(head->next==tail && tail->previous==head){
    return true;
  }
  return false;
}

void List::makeEmpty(){
  ListItr itr=ListItr(head->next);
  if(!isEmpty()){
    while(itr.current->next!=NULL){
      itr.current=itr.current->next;
      delete itr.current->previous;
      itr.current->previous=NULL;
    }
    head->next=tail;
    tail->previous=head;
  }
}

ListItr List::first(){
  ListItr itr=ListItr(head->next);
  return itr;
}

ListItr List::last(){
  ListItr itr=ListItr(tail-> previous);
  return itr;
}

void List::insertAfter(int x, ListItr position){
  ListNode* newNode=new ListNode(x);
  ListItr position2(position.current->next);
  position.current->next=newNode;
  newNode->previous=position.current;
  if(position2.current==tail){
    tail->previous=newNode;
    newNode->next=tail;
  }
  else{
    position2.current->previous=newNode;
    newNode->next=position2.current;
  }
  count++;
}

void List::insertBefore(int x, ListItr position){
  ListNode* newNode=new ListNode(x);
  ListItr position2 (position.current->previous);
  position.current->previous=newNode;
  newNode->next=position.current;
  if(position2.current==head){
    head->next=newNode;
    newNode->previous=head;
  }
  else{
    position2.current->next=newNode;
    newNode->previous=position2.current;
  }
  count++;
}

void List::insertAtTail(int x){
    ListNode* newNode=new ListNode(x);
    last().current->next=newNode;
    newNode->previous=last().current;
    newNode->next=tail;
    tail->previous=newNode;
    count++;
}

void List::insertAtHead(int x){
    ListNode* newNode=new ListNode(x);
    first().current->previous=newNode;
    newNode->next=first().current;
    newNode->previous=head;
    head->next=newNode;
    count++;
}

ListItr List::find(int x){
   ListItr itr= ListItr(head);
   while (!itr.isPastEnd()){
    if(itr.current->value!=x){
      itr.moveForward();
    }
    if(itr.current->value==x){
      break;
    }
  }
  return itr;
}

void List::remove(int x){
  ListItr itr=find(x);
  if(itr.current!=tail){
    if(itr.current->previous==head && itr.current->next==tail){
      head->next=tail;
      tail->previous=head;
    }
    else if(itr.current->previous==head){
      head->next=itr.current->next;
      itr.current->next->previous=head;
    }
    else if(itr.current->next==tail){
      tail->previous=itr.current->previous;
      itr.current->previous->next=tail;
    }
    else{
      itr.current->next->previous=itr.current->previous;
      itr.current->previous->next=itr.current->next;
      itr.current=itr.current->next;
      delete itr.current->previous;
      itr.current->previous=NULL;
    }
    count--;
  }
}

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
  if(forward){
    ListItr itr=ListItr(source.first());
    while(!itr.isPastEnd()){
      cout<<itr.retrieve()<<endl;
      itr.moveForward();
    }
  }
  if(!forward){
    ListItr itr=ListItr(source.last());
    while(!itr.isPastBeginning()){
      cout<<itr.retrieve()<<endl;
      itr.moveBackward();
    }
  }
}
