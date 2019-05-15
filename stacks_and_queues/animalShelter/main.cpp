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
  // ~LinkedList();

  // print 
  void print(std::ostream &out) const;
  friend std::ostream& operator<< (std::ostream &out, const LinkedList &l);

  // adopt a new animal to the shelter
  Node *push(Node *_newAnimal);

};

// LinkedList::~LinkedList()
// {
//   Node *current = head;
//   Node *tmp = head;

//   while (current != 0)
//   {
//     current = current->getNext();
//     delete tmp;
//     tmp = current;
//   }
// }

Node *LinkedList::push(Node *_newAnimal)
{
 
  // if this is the first element, dynamically allocate
  if (head == 0)
  {
    
    head = new Node(_newAnimal);

    return head;
  }

  else
  {
    // start with the first one
    Node *current = head;

    // go to the tail of the list
    while(current -> getNext() != 0)
    {
      current = current -> getNext();
    }


    // dynamically allocate for the tail
    current = new Node;
    current = _newAnimal;

    return current;
  }
  
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
  
  while (current->getNext() != 0)
  {
    std::cout << "->" << *current;
  }
}


LinkedList::LinkedList(Node *_head, Cat *_headCat, Dog *_headDog)
: head(_head), headCat(_headCat), headDog(_headDog){}


int main() {
  
  // std::cout << "here";
  LinkedList l;
  Cat *c1;

  // l.head = new Node;
  
  Node *head = new Node;
  std::cout << head << ' ' << c1;

  // std::cout << l;

  return 0;
}