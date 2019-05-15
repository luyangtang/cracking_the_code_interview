#include <iostream>


#include <iostream>
#include <cassert>
#include "Node.h"

class LinkedList
{

public:
  Node *head;
  Cat *headCat;
  Dog *headDog;

public:
  // constructor
  LinkedList(Node *_head = 0, Cat *_headCat = 0, Dog *_headDog = 0);
  ~LinkedList();

  // print 
  void print(std::ostream &out) const;
  friend std::ostream& operator<< (std::ostream &out, const LinkedList &l);

  // adopt a new animal to the shelter
  Node *push(const Node &_newAnimal);

};

LinkedList::~LinkedList()
{
  Node *current = head;
  Node *tmp = head;

  while (current != 0)
  {
    current = current->getNext();
    delete tmp;
    tmp = current;
  }
}

Node *LinkedList::push(const Node &_newAnimal)
{
 
  // start with the first one
  Node *current = head;

  // if this is the first element, dynamically allocate
  if (head == 0)
  {

    head = new Node(_newAnimal);

    current = head;
  }

  else
  {
    
    // go to the tail of the list
    while(current -> getNext() != 0)
    {
      current = current -> getNext();
    }

    // dynamically allocate for the tail
    current -> createNext(_newAnimal);

    
  }
  
  return current;
}


std::ostream& operator<< (std::ostream &out, const LinkedList &l)
{
  l.print(out);
  return out;
}


void LinkedList::print(std::ostream &out) const
{
  assert(head != 0);

  Node *current = head;
  std::cout << *current;

  while (current->getNext() != 0)
  {
    current = current->getNext();
    std::cout << "->" << *current;
  }
}


LinkedList::LinkedList(Node *_head, Cat *_headCat, Dog *_headDog)
: head(_head), headCat(_headCat), headDog(_headDog){}


int main() {
  
  // std::cout << "here";
  LinkedList l;

  l.push(Cat());
  l.push(Dog());
  l.push(Dog());
  l.push(Dog());
  l.push(Dog());
  l.push(Cat());
  l.push(Cat());
  
  std::cout << l << ' ';


  return 0;
}