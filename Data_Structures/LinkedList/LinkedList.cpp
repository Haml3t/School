#include "LinkedList.h"
// compile with -std=c++0x argument
class LinkedList::Node
{
public:
  Node(int data, Node* next = nullptr);
  void setNext(Node *next);
private:
  int data;
  Node* next;
};

LinkedList::LinkedList()
{
  head = nullptr;
  size = 0;
}

void LinkedList::insertAtHead(int data)
{
  head = new Node(data, head);
  size++;
};

LinkedList::Node::Node(int data, Node *next)
{
  this->data = data;
  this->next = next;
}

void LinkedList::Node::setNext( Node *next )
{
  this->next = next;
}
