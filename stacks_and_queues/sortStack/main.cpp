#include <iostream>
#include "quickSort.h"
#include "Stack.h"







int main() {
  
  Stack s;
  s.push(2);
  s.push(5);
  // s.push(6);
  // s.push(3);
  // s.push(8);
  // s.push(7);
  // s.push(1);
  // s.push(0);

  std::cout << s;

  quickSort(s);
  std::cout << s;


  return 0;
  
}