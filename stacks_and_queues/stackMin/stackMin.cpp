#include "Stack.h"
#include <initializer_list>
#define MAX 10000

Stack::~Stack()
{
  delete[] arr;
  delete[] min;
}


void Stack::initialisation(const std::initializer_list<int> &l)
{
  arr = new int[MAX];
  min = new int[MAX];

  // counter
  int i = 0;

  for (std::initializer_list<int>::iterator it = l.begin(); it != l.end(); it++)
  {
    min[i] = (i == 0 ? (*it) : (min[i-1] < (*it) ? min[i-1] : (*it)));
    arr[i++] = *it;
  }
}

int Stack::get_min() const
{
  return min[top-1];
}

int Stack::push(int _new)
{
  // update min
  min[top] = (min[top - 1] < _new ? min[top - 1] : _new);
  // add the element to arr
  arr[top++] = _new;
  return _new;
}

int Stack::pop()
{
  return arr[--top];
}

std::ostream& operator<<(std::ostream &out, const Stack &s)
{
  out << "Stack ";
  for (int i = 0; i < s.top; i++)
  {
    out << s.arr[i] << ' ';
  }
  out << ", the minimum is " << s.get_min() << '\n';
  return out;
}

void testStackMin()
{
  Stack s = {4,3,2,1};
  std::cout << s << '\n';
  s.pop();
  std::cout << s << '\n';
  s.pop();
  std::cout << s << '\n';
  s.push(6);
  std::cout << s << '\n';
  s.push();
  std::cout << s << '\n';
}
