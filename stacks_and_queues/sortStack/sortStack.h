#include <iostream>
#include "Stack.h"

void sortStack(Stack &s, Stack &helper);
void print(Stack &s, Stack &helper);
void testSortStack();
void testSortStackAsMember();


void testSortStackAsMember()
{
  // define a stack
  Stack s;
  s.push(1);
  s.push(3);
  s.push(2);
  s.push(4);
  

  // sort
  s.sort();
  
}

void Stack::sort()
{
  Stack helper;
  sortStack(*this, helper);
}

void print(Stack &s, Stack &helper)
{
  std::cout << s;
  std::cout << helper;
  std::cout << '\n';
}


void sortStack(Stack &s, Stack &helper)
{
  int candidate;

  // take an element from the stack
  while(!s.isEmpty())
  {
    // std::cout << "loop\n";

    candidate = s.pop();

    // if helper is empty, push it there
    if(helper.isEmpty())
    {
      helper.push(candidate);
    }

    // otherwise compare the top of the helper with the candidate
    else if (helper.peek() <= candidate)
    {
      // if the helper's peek is less than the candidate then push it to the helper
      helper.push(candidate);
    }

    // if the helper's peek is larger
    else
    {
      while (helper.getTop() > 0 && helper.peek() > candidate)
      {
        // move the top of helper to the original stack
        s.push(helper.pop());
      }

      // push the candidate to the helper
      helper.push(candidate);
    }

    print(s, helper);
  }
}


void testSortStack()
{
  // define a stack
  Stack s;
  s.push(1);
  s.push(3);
  s.push(2);
  s.push(4);

  // have a helper stack
  Stack helper;

  print(s,helper);

  sortStack(s,helper);

  print(s,helper);
}
