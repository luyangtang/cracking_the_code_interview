#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <cassert>


Queue::~Queue()
{
  delete[] stacks;
}

Queue::Queue()
: current(0)
{
  stacks = new Stack[2];
}

int Queue::pop()
{
  // swap the arrays
  swap();

  // pop from current
  int popped = stacks[current].pop();

  // swap back
  swap();

  return popped;
}


int Queue::push(int _new)
{
  // check if the stack is full
  assert(stacks[current].getTop() < stacks[current].getCapacity());

  // push
  return stacks[current].push(_new);
}

void Queue::swap()
{
  // pop from current and push to spare
  int len = stacks[current].getTop();
  for (int i = 0; i < len; i++)
  {
    stacks[1 - current].push(stacks[current].pop());
  }

  // swap the current state
  current = 1 - current;
}

std::ostream& operator<<(std::ostream &out, const Queue &q)
{
  out << "Queue\n-----\nCurrent: " << q.stacks[q.current] << "Spare: " << q.stacks[1 - q.current] << "-----\n\n";

  return out; 
}


void testQueue()
{
  Queue q;

  std::cout << q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  std::cout << q;


  q.pop();
  q.pop();
  std::cout << q;
}
