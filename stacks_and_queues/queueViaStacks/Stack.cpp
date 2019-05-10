#include <iostream>
#include <cassert>
#include "Stack.h"
#define MAX 10000

int Stack::capacity = MAX;

Stack::Stack()
: top(0)
{
  arr = new int[getCapacity()];
}

int Stack::getTop()
{
  return top;
}


int Stack::getCapacity()
{
  return capacity;
}

Stack::~Stack()
{
  delete[] arr;
}


void testStack()
{
  Stack s;
  std::cout << s;

  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << s;

  s.pop();
  std::cout << s;
}

bool Stack::isEmpty() const
{
  return (top == 0);
}

int Stack::peek() const
{
  assert(!isEmpty());
  return arr[top - 1];
}

int Stack::pop()
{
  assert(!isEmpty());
  return arr[--top];
}

int Stack::push(int _new)
{
  assert(top < getCapacity());
  arr[top++] = _new;
  return _new;
}



std::ostream& operator<<(std::ostream &out, const Stack &s)
{
  s.print(out);

  if (!s.isEmpty())
  {
    out << ". Peek at " << s.peek();
  }

  out << '\n';
  return out;
}


void Stack::print(std::ostream &out) const
{
  out << "Stack(";

  for (int i = 0; i < top; i++)
  {
    out << arr[i] << ' ';
  }
  out << ')';
}

