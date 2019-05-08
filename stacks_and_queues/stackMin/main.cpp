#include <iostream>
#include "Stack.h"



#include <initializer_list>
#define MAX 10000


class StackBase
{
private:
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

  // member functions
  int pop();
  int push(int _new = 0);
  int peek();
};

int StackBase::peek()
{
  return arr[top - 1];
}

int StackBase::push(int _new)
{
  arr[top++] = _new;
  return arr[top - 1];
}

int StackBase::pop()
{
  return arr[--top];
}


std::ostream& operator<<(std::ostream &out, const StackBase &s)
{
  out << "Stack ";

  for (int i = 0; i < s.top; i++)
  {
    out << s.arr[i] << ' ';
  }
  out << '\n';

  return out;
}



StackBase::StackBase()
  : top(0)
{
  arr = new int [MAX];
}

StackBase::StackBase(const std::initializer_list<int> &l)
  : top(l.size())
{
  arr = new int [MAX];

  // counter
  int i = 0;

  for (std::initializer_list<int>::iterator it = l.begin(); it != l.end(); it++)
  {
    arr[i++] = (*it);
  }
}


StackBase::~StackBase()
{
  delete[] arr;
}


class Stack2 : public StackBase
{
private:
  int top;
  int *arr;
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

  // // print
  // friend std::ostream& operator<<(std::ostream &out, const Stack2 &s);
};

Stack2::~Stack2()
{
  delete min;
  delete[] arr;
}

// std::ostream& operator<<(std::ostream &out, const Stack2 &s)
// {
//   out << s << ". The minimum is " << s.min;

//   return out;
// }


int Stack2::push(int _new)
{
  if(_new <= get_min())
    min->push(_new);

  return arr[top++] = _new;
}

int Stack2::get_min() const
{
  return min->peek();
}

int Stack2::pop()
{
  if (arr[top - 1] == get_min())
    min->pop();
  return arr[top--];
}


Stack2::Stack2()
  :top(0)
  {
    arr = new int[MAX];
    min = new StackBase;
  }

Stack2::Stack2(const std::initializer_list<int> &l)
  : StackBase(l)
  {

    std::cout << top;
    
    min = new StackBase;

    // keep a counter
    int i = 0;
    min->push(arr[i]);

    for (int i = 1; i < top; i++)
    {
      // std::cout << arr[i];
      if (arr[i] <= min->peek())
      {
        min->push(arr[i]);
        std::cout << *min;
      }
    }
    
  }


int main() {
  
  Stack2 s = {4,3,2};
  std::cout << s;

  return 0;

}