#include "Stack.h"
#include <iostream>

void halveStack(Stack &s, Stack &a, Stack &b);
void _mergeSort(Stack &s);
void testMergeSort();
void testMergeSortInClass();




void testMergeSortInClass()
{
  Stack s;
  s.push(0);
  s.push(2);
  s.push(1);
  s.push(0);
  s.push(4);
  s.push(3);
  s.push(1);

  std::cout << s;

  s.mergeSort();
  std::cout << s;

}



void Stack::mergeSort()
{
  _mergeSort(*this);
}

void testMergeSort()
{
  Stack s;
  s.push(0);
  s.push(2);
  s.push(1);
  s.push(0);
  s.push(4);
  s.push(3);

  std::cout << s;

  _mergeSort(s);
  std::cout << s;
}


void halveStack(Stack &s, Stack &a, Stack &b)
{
  // cut it half way (division will be promoted to int)
    int halfCount = s.getTop() / 2;

  // populate the stacks by splitting the original stack
    while (!s.isEmpty())
    {
      if (s.getTop() <= halfCount)
      {
        // send to a
        a.push(s.pop());
      }
      else
      {
        // send to b
        b.push(s.pop());
      }
    }
}



void _mergeSort(Stack &s)
{
  // do nothing for base case
  if (s.getTop() != 1)
  {
    // two tmp stacks
    Stack a, b;
    Stack sh; // s hat, for pouring into s

    // halve the stack
    halveStack(s, a, b);

    // sort both stack by recursive call
    _mergeSort(a);
    _mergeSort(b);

    // std::cout << "a, b: " << a << b;

    // stitch the stacks
    while (!a.isEmpty() && !b.isEmpty())
    {
      // for asending order, push the large one first to the base stack
      if (a.peek() <= b.peek())
      {
        sh.push(b.pop());
      }
      else
      {
        sh.push(a.pop());
      }
    }

    // which ever has something left, populate to stack
    while (!a.isEmpty())
    {
      sh.push(a.pop());
    }

    while (!b.isEmpty())
    {
      sh.push(b.pop());
    }

    // pour everything from sh to s
    while (!sh.isEmpty())
    {
      s.push(sh.pop());
    }
    
    // std::cout << "s: " << s << '\n';
  }
}