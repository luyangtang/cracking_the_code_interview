
#include "Queue2.h"
#include "Stack.h"
#include <iostream>
#include <cassert>

int Queue2::dequeue()
{
  // if nothing in old
  if (o->isEmpty())
  {
    switchStack();
  }

  // always pop from old
  int popped = o->pop();
  std::cout << popped << " is popped\n";
  return popped;
} 


void Queue2::switchStack()
{
  // only do when old is empty and new not empty
  assert(o->isEmpty() && !(n->isEmpty()));

  // shift the stack
  while (!n->isEmpty())
  {
    o->push(n->pop());
  }
}

int Queue2::push(int _new)
{
  return n->push(_new);
}

std::ostream& operator<<(std::ostream &out, const Queue2 &q)
{
  q.print(out);

  return out;
}


void Queue2::print(std::ostream &out) const
{
  out << "Queue\n-----\nNew: " << (*n) << "Old :" << (*o) << "-----\n\n";
}

Queue2::~Queue2()
{
  delete n;
  delete o;
}

Queue2::Queue2()
{
  n = new Stack;
  o = new Stack;
}


void testQueue2()
{
  Queue2 q;
  std::cout << q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  std::cout << q;


  q.dequeue();
  q.dequeue();
  q.dequeue();
  std::cout << q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  std::cout << q;
}

