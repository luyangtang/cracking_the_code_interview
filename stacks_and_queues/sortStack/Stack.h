#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <cassert>
#define MAX 10000


void testStack();

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

  // action
  bool isEmpty();
  int push(int _new = 0);
  int pop();
  int peek();
  void sort();
  void mergeSort();

  // get
  int getTop();
};



int Stack::push(int _new)
{
  assert(top < capacity);
  arr[top++] = _new;
  return _new;
}

int Stack::pop()
{
  assert(top > 0);
  return arr[--top];
}

int Stack::peek()
{
  assert(top > 0);
  return arr[top - 1];
}


std::ostream& operator<<(std::ostream &out, const Stack &s)
{
  s.print(out);
  out << '\n';
  return out;
}

int Stack::getTop()
{
  return top;
}

bool Stack::isEmpty()
{
  return (top == 0);
}

void Stack::print(std::ostream &out) const
{
  out << "Stack(";
  for (int i = 0; i < top; i++)
  {
    out << arr[i] << ' ';
  }
  out << ")";
}


int Stack::capacity = MAX;

Stack::~Stack()
{
  delete[] arr;
}

Stack::Stack()
:top(0)
{
  arr = new int[capacity];
}


void testStack()
{
  Stack s;
  std::cout << s;

  s.push();
  s.push();
  s.push();
  std::cout << s;

  s.pop();
  s.pop();
  std::cout << s;
}

#endif