#ifndef STACK2_H
#define STACK2_H


#include <initializer_list>
#define MAX 10000


class StackBase
{
protected:
  int top;
  int *arr;

public:
  //constructor
  StackBase();
  StackBase(const std::initializer_list<int> &l);
  // destructor
  ~StackBase();

  // print
  friend std::ostream& operator<< (std::ostream &out, const StackBase &s);
  std::ostream& print(std::ostream &out) const;

  // member functions
  int pop();
  int push(int _new = 0);
  int peek();
};



class Stack2 : public StackBase
{
private:
  StackBase *min; // implement min in a stack

public:

  // constructor
  Stack2();
  Stack2(const std::initializer_list<int> &l);
  ~Stack2();


  // member functions
  int pop();
  int push(int _new);
  int get_min() const;

  // print
  std::ostream& print(std::ostream &out);
};



void testStack2();

#endif