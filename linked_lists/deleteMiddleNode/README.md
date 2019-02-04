# 2.3 Delete Middle node

Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.

EXAMPLE

lnput:the node c from the linked list a->b->c->d->e->f

Result: nothing is returned, but the new linked list looks like a->b->d->e->f

[deleteMiddleNode](./deleteMiddleNode/mySolution.cpp) move the data sequentially and detach the final one.

From the book: Note that this problem cannot be solved if the node to be deleted is the last node in the linked list.
