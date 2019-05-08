#include <initializer_list>
#include <iostream>
#include "Stack2.h"



std::ostream& Stack2::print(std::ostream &out)
{
  const StackBase *b = this;
  b->print(out);
  out << ". Minimum is " << get_min(); 

  return out;
}

Stack2::~Stack2()
{
  delete min;
}


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
  : StackBase()
  {
    min = new StackBase;
  }

Stack2::Stack2(const std::initializer_list<int> &l)
  : StackBase(l)
  {
    
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
      }
    }
  }

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

std::ostream& StackBase::print(std::ostream &out) const
{
  out << "Stack ";

  for (int i = 0; i < top; i++)
  {
    out << arr[i] << ' ';
  }

  return out;
}

std::ostream& operator<<(std::ostream &out, const StackBase &s)
{
  s.print(out);

  out << '\n';
  return out;
}



StackBase::StackBase()
  : top(0)
{
  arr = new int [MAX];
}

StackBase::StackBase(const std::initializer_list<int> &l)
  : top(static_cast<int>(l.size()))
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