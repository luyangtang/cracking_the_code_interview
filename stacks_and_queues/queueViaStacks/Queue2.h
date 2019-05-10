#ifndef QUEUE2_H
#define QUEUE2_H


#include "Stack.h"
#include <cassert>
#include <iostream>

class Queue2
{
private:
  Stack *n;
  Stack *o;

public:
  //constructor
  Queue2();
  ~Queue2();

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<< (std::ostream &out, const Queue2 &q);

  // actions
  int push(int _new = 0);
  int dequeue();
  int peek();
  void switchStack();
};


void testQueue2();

#endif