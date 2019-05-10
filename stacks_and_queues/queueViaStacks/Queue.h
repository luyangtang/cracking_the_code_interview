#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include "Stack.h"

class Queue
{
private:
  Stack* stacks;
  int current;

  
  // swap roles (cuurent vs spare)
  void swap();

public:
  // constructor
  Queue();
  ~Queue();

  // print
  friend std::ostream& operator<<(std::ostream &out, const Queue &q);

  

  // actions
  int peek();
  int push(int _new);
  int pop();

};

void testQueue();



#endif