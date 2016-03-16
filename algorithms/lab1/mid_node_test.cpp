#include "sort.h"
using namespace std;

int main() {
  // int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // int firstList[] = {1, 4, 7, 8};
  // int secondList[] = {2, 3, 5};
  //   int firstList[] = {1};
  // int secondList[] = {3};
  // LinkedListNode *firstLinkedList = createLinkedList(firstList, 4);
  // LinkedListNode *secondLinkedList = createLinkedList(secondList, 3);
  // LinkedListNode *dubstep = mergeSortedLinkedLists(firstLinkedList, secondLinkedList);
  // cout << "dubstep: " << linkedListToString(dubstep, "->") << endl;
  // LinkedListNode *list = createLinkedList(numbers, 9);
  // LinkedListNode *mid = mid_node(list);
  // cout << "Value of midpoint should be 5" << endl;
  // cout << mid->value << endl;
  int numbers[] = {3, 2, 6, 88, 2, 45, 12, 578, 3, -45, -76, 23, 1, 32};
  // int numbers [] = {3, 1};
  LinkedListNode *numeros = createLinkedList(numbers, 14);
  cout << linkedListToString(numeros, "->") << endl;
  LinkedListNode *dubstep2 = sortLinkedList(numeros);
  cout << "sorted (in theory): " << linkedListToString(dubstep2, "->") << endl;
}
