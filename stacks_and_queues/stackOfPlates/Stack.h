#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <initializer_list>

class Stack
{
private:
  int top;
  int *arr;
  static int capacity;

public:
  // constructor
  Stack();
  Stack(const std::initializer_list<int> &l);
  ~Stack();

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<<(std::ostream &out, const Stack &s);

  // actions
  int pop();
  int push(int _new = 0);
  int peek();

  // get capacity
  int getCapacity();
  int size();

};

void testStack();


#endif