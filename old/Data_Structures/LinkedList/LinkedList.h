#ifndef DAVID_LINKEDLIST_H
#define DAVID_LINKEDLIST_H

#include <stddef.h>

// template class // not used because complicated--return to this later. Allows for generic data type inserted into node (?)
class LinkedList {
 public:
  LinkedList();			/* default constructor, to be overridden */
  void insertAtHead(int);
  size_t getSize() const { return size; }; /* needs to be getSize() as opposed to Size because that clashes with size_t size in private part */

 private:
  class Node;			/* "inner class"--only used for internal purposes. User never has direct access */
  Node *head; // pointing to dynamic memory, not static memory; not automatically cleared from memory. Same as Node* head
  size_t size;

};

#endif DAVID_LINKEDLIST_H
