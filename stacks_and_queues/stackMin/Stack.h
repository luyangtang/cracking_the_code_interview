#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <initializer_list>

class Stack
{
private:
  int top;
  int *arr;
  int *min; // track the minimums wrt top

public:

  // constructor from an initialisation list
  Stack(const std::initializer_list<int> &l)
  : top(l.size()), min(0) // always initialise
  {
    initialisation(l);
  }


  // deconstructor
  ~Stack();

  void initialisation(const std::initializer_list<int> &l);

  // print the stack
  friend std::ostream& operator<<(std::ostream &out, const Stack &s);

  // member functions
  int pop();
  int push(int _new = 0);
  int get_min() const;
  
};


void testStackMin();


#endif