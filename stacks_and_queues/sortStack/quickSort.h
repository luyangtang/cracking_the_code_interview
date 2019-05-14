#include "Stack.h"
#include <iostream>


void quickSort(Stack &s);

void quickSort(Stack &s)
{
  Stack sh; // s hat as a helper stack

  // no need to sort if s.top == 1
  if (s.getTop() == 2)
  {
    // sort two element stack is trivial
    sh.push(s.pop());
    if (s.peek() < sh.peek())
    {
      // for ascending order, swap the two
      int tmp = s.pop();
      s.push(sh.pop());
      s.push(tmp);
    }
  }

  // for a longer stack
  else if (s.getTop() > 2)
  {
    // Step 1: find the pivot
    
  }

}