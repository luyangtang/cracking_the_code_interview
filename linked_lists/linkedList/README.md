# Linked Lists


```
class Node {
  Node next= null;
  int data;

  public Node(int d)
  {
    data= d;
  }

void appendToTail(int d)
{
  Node end= new Node(d);
  Node n = this;
  while (n.next != null)
  {
    n = n.next;
  }
  n.next= end;
}
```

`LinkedList` structure is not present here. We may want to implement a data structure that wraps so that we won't get into trouble when the `HEAD` is changed and multiple objects are pointing to the `HEAD`.


[myLinkedList](./linkedList/myLinkedList.cpp) is an implementation of (single) linked list as a data structure. Updated with `remove(int i)` method which deletes the i-th entry.
