#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

#include <iostream>
#include "Stack.h"


void testSetOfStacks();

class SetOfStacks
{
private:
  Stack *set;
  int stackCount;
  
public:
  // constructor
  SetOfStacks();
  ~SetOfStacks();

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<<(std::ostream &out, const SetOfStacks &ss);

  // action
  void addStack(const Stack &s); // for anonymous variable
  void addStack(Stack &s);
  int push(int _new = 0);
  int pop();
  int popAt(int index);

  // get
  int size() const;
  Stack* arr() const;
};


#endif