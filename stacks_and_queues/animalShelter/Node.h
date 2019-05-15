#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <string>


void testNode();


class Node
{
protected:
  std::string data;
  Node *next;

public:
  // constructor
  Node(std::string _data = "animal", Node *_next = 0);
  Node(Node *n); // copy

  // get function
  Node *getNext();
  Node *createNext(const Node &_next);

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<< (std::ostream &out, const Node &n);
};


class Cat : public Node
{
private:
  Cat *nextCat;

public:
  Cat(std::string _data = "cat", Node *_next = 0, Cat *_nextCat = 0);
  Cat(Cat *_c);

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<< (std::ostream &out, const Cat &c);
};


class Dog : public Node
{
private:
  Dog *nextDog;

public:
  Dog(std::string _data = "dog", Node *_next = 0, Dog *_nextDog = 0);
  Dog(Dog *_d);

  // print
  void print(std::ostream &out) const;
  friend std::ostream& operator<< (std::ostream &out, const Dog &d);
};


Node *Node::createNext(const Node &_next)
{
  next = new Node(_next);
  return next;
}

Cat::Cat(Cat *_c)
: Node(_c)
{
  nextCat = _c->nextCat;
}


Dog::Dog(Dog *_d)
: Node(_d)
{
  nextDog = _d->nextDog;
}


Node::Node(Node *n)
{
  data = n->data;
  next = n->next;
}


void testNode()
{

  Node n("node1");

  std::cout << n << '\n';

  Cat c("cat");
  std::cout << c << '\n';

  Dog d("dog");
  std::cout << d << '\n';


}


Node *Node::getNext()
{
  return next;
}

void Dog::print(std::ostream &out) const
{
  out << "Dog (" << data << ')';
}

std::ostream& operator<< (std::ostream &out, const Dog &d)
{
  d.print(out);
  return out;
}


Dog::Dog(std::string _data, Node *_next, Dog *_nextDog)
: Node(_data, _next), nextDog(_nextDog){}


void Cat::print(std::ostream &out) const
{
  out << "Cat (" << data << ')';
}

std::ostream& operator<< (std::ostream &out, const Cat &c)
{
  c.print(out);
  return out;
}


Cat::Cat(std::string _data, Node *_next, Cat *_nextCat)
: Node(_data, _next), nextCat(_nextCat){}



std::ostream& operator<< (std::ostream &out, const Node &n)
{
  n.print(out);
  return out;
}

void Node::print(std::ostream &out) const
{
  out << data;
}

Node::Node(std::string _data, Node *_next)
: data(_data), next(_next){}




#endif