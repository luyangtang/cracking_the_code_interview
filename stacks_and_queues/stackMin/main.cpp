#include <iostream>
#include "Stack2.h"


void testStack2()
{
  Stack2 s = {4,3,2};
  std::cout << s;
  std::cout << "minimum is " << s.get_min() << '\n';

  s.pop();
  std::cout << s;
  std::cout << "minimum is " << s.get_min() << '\n';

  s.push(6);
  std::cout << s;
  std::cout << "minimum is " << s.get_min() << '\n';

}


int main() {
  
  testStack2();

  return 0;

}