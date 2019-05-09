
#include "SetOfStacks.h"
#include "Stack.h"
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <limits.h>
#define MAX 100

void testSetOfStacks()
{

  SetOfStacks ss;
  ss.addStack(Stack());
  std::cout << ss;

  ss.push(0);
  ss.push(0);
  ss.push(0);
  ss.push(0);
  ss.push(0);
  std::cout << ss;

  ss.push(0);
  std::cout << ss;

  ss.pop();
  ss.pop();
  std::cout << ss;
  
  ss.push(0);
  ss.push(0);
  ss.push(0);
  std::cout << ss;

  ss.popAt(0);
  ss.popAt(1);
  ss.popAt(1);
  ss.popAt(1);
  std::cout << ss;
}


int SetOfStacks::popAt(int index)
{
  try
  {
    return set[index].pop();
  }
  catch(std::out_of_range &e)
  {
    std::cout << e.what();
    return INT_MAX;
  }
}


int SetOfStacks::pop()
{
  if (stackCount <= 1 && set[stackCount - 1].size() == 0)
    throw std::out_of_range("no data to pop\n");
  try
  {
    Stack &s = set[stackCount - 1];
    return s.pop();
  }
  catch (std::out_of_range &e)
  {
    Stack &s = set[--stackCount - 1];
    return s.pop();
  }
  
}

int SetOfStacks::push(int _new)
{
  try
  {
    set[stackCount - 1].push(_new);
  }
  catch(std::length_error &e)
  {
    set[stackCount++].push(_new);
  }
  return _new;
}

Stack* SetOfStacks::arr() const
{
  return set;
}

int SetOfStacks::size() const
{
  return stackCount;
}

void SetOfStacks::addStack(const Stack &s)
{
  set[stackCount++] = s;
}

void SetOfStacks::addStack(Stack &s)
{
  set[stackCount++] = s;
}

std::ostream& operator<<(std::ostream &out, const SetOfStacks &ss)
{
  ss.print(out);
  return out;
}

void SetOfStacks::print(std::ostream &out) const
{
  out << "Set of Stack\n------\n";
  for (int i = 0; i < stackCount; i++)
  {
    out << i << ": " << set[i];
  }
  out << "------\n\n";
}

SetOfStacks::~SetOfStacks()
{
  delete[] set;
}


SetOfStacks::SetOfStacks()
{
  set = new Stack[MAX];
  stackCount = 0;
}