// David Sugarman 5364
#include <sstream>
#include "sort.h"

// The LinkedListNode constructor.
LinkedListNode::LinkedListNode(int value) {
    this->next = NULL;
    this->value = value;
}

/*
The in-place merge sort function for linked lists.

The function sorts the given linked list in place, i.e., no new linked
list nodes should be created. It should also run in O(n log n) time as
the regular merge sort algorithm.
 */
LinkedListNode *sortLinkedList(LinkedListNode *list) {
  if (list->next == NULL)
    return list;
  else {
    LinkedListNode *slow = list;
    LinkedListNode *fast = list;
    while(fast->next != NULL) {
      fast = fast->next;
      if (fast->next != NULL) {
	fast = fast->next;
	slow = slow->next;
      }
    }
    LinkedListNode *midnode = slow->next;
    slow->next = NULL;
    LinkedListNode *a = sortLinkedList(list);
    LinkedListNode *b = sortLinkedList(midnode);
    LinkedListNode *merged_result = mergeSortedLinkedLists(a, b);
    return merged_result;
  }
}

/*
The merge function for sorted linked lists.

The function takes as inputs two sorted linked lists and outputs the merge
of those lists. The merged list must also be sorted. The implementation should
use O(1) additional storage. It should reuse the nodes from the lists provided
as inputs.
 */
LinkedListNode *mergeSortedLinkedLists(LinkedListNode *firstList, LinkedListNode *secondList) {
  if (firstList == NULL) {
    return secondList;
  }
  if (secondList == NULL) {
    return firstList;
  }
  LinkedListNode *a = firstList;
  LinkedListNode *b = secondList;
  LinkedListNode *c;
  LinkedListNode *merged;
  if (a->value <= b->value) {
    merged = a;
    a = a->next;
  }
  else {
    merged = b;
    b = b->next;
  }
  c = merged;
  while (c != NULL) {
    if (a == NULL) {
      c->next = b;
      break;
    }
    else if (b == NULL) {
      c->next = a;
      break;
    }
    else if (a->value <= b->value) {
      c->next = a;
      a = a->next;
      c = c->next;
    }
    else {
      c->next = b;
      b = b->next;
      c = c->next;
    }
  }
    return merged;
}

// Creates a linked list from the integers in the given array.
LinkedListNode *createLinkedList(int *numbers, int length) {
    if (length == 0)
	return NULL;
    LinkedListNode *head, *tail;
    head = tail = new LinkedListNode(numbers[0]);
    for (int i = 1; i < length; i++) {
	LinkedListNode *node = new LinkedListNode(numbers[i]);
	tail->next = node;
	tail = node;
    }
    return head;
}

// Converts a linked list to a human-readable string.
string linkedListToString(LinkedListNode *head, string edge) {
    stringstream output;
    while (head) {
	output << head->value;
	if (head->next)
	    output << edge;
	head = head->next;
    }
    return output.str();
}
