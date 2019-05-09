#include <iostream>
#include <initializer_list>
#include "Stack.h"
#include <cassert>
#include <stdexcept>
#define STACK_MAX 5


int Stack::capacity = STACK_MAX;

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
  Stack s = {4,3,1};
  std::cout << s;
  s.pop();
  std::cout << s;
  s.pop();
  std::cout << s;
  s.pop();
  std::cout << s;
  s.pop();
  std::cout << s;
  s.push(5);
  std::cout << s;
  s.push(5);
  std::cout << s;
  s.push(5);
  std::cout << s;
  s.push(5);
  std::cout << s;
  s.push(5);
  std::cout << s;
  s.push(5);
  std::cout << s;

  Stack s2 = {4,3,2,1,0,1,5};
  std::cout << s2;

}

int Stack::size()
{
  return top;
}

int Stack::pop()
{
  if (top < 1)
    throw std::out_of_range("no more element to pop\n");
  return arr[--top];
}

int Stack::push(int _new)
{
  if (top >= capacity)
    throw std::length_error("exceed stack capacity\n");
  else
  {
    arr[top++] = _new;
    return peek();
  }
  
}

int Stack::peek()
{
  return arr[top - 1];
}


void Stack::print(std::ostream &out) const
{
  out << "Stack ";

  for (int i = 0; i < top; i++)
  {
    out << arr[i] << ' '; 
  }
}

std::ostream& operator<<(std::ostream &out, const Stack &s)
{
  
  s.print(out);
  out << '\n';
  return out;
}

Stack::Stack()
:top(0)
{
  arr = new int [getCapacity()];
}


Stack::Stack(const std::initializer_list<int> &l)
: top(l.size() > capacity ? capacity : l.size())
{
  // dynamically allocate the array with max capacity
  arr = new int[getCapacity()];

  // counter
  int i = 0;

  
  // populate the array
  for (std::initializer_list<int>::iterator it = l.begin(); it != l.end(); it++)
  {
    if (i >= getCapacity())
      throw std::length_error("initialization exceed stack capacity\n");
    arr[i++] = (*it);
  }
  

}