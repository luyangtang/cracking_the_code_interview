#ifndef STACK_H
#define STACK_H


#include <iostream>
class Stack
{
private:
  int top;
  int *arr;
  static int capacity;

public:
  // constructor
  Stack();
  ~Stack();

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<<(std::ostream &out, const Stack &s);

  // actions
  int peek() const;
  int pop();
  int push(int _new = 0);
  bool isEmpty() const;

  // get
  int getTop();
  int getCapacity();
};


void testStack();


#endif