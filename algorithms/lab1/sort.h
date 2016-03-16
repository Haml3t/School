#include <iostream>
#include <ostream>
#ifndef SORT_H_
#define SORT_H_

using namespace std;

// The linked list node struct
struct LinkedListNode {
    LinkedListNode *next;
    int value;

    LinkedListNode(int);
};

// Sorting functions
LinkedListNode *sortLinkedList(LinkedListNode *);

LinkedListNode *mergeSortedLinkedLists(LinkedListNode *, LinkedListNode *);

// Miscellaneous functions
LinkedListNode *createLinkedList(int *, int);

string linkedListToString(LinkedListNode *, string edge);

#endif /* SORT_H_ */
