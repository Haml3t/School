#include <string>
#include "btree.h"
#include <iostream>
#include <ostream>

using namespace std;

int main() {
  BTreeNode *root = new BTreeNode(); // create empty BTree
  bTreeInsert(root, 'D');
  bTreeInsert(root, 'L');
  bTreeInsert(root, 'J');
  bTreeInsert(root, 'X');
  bTreeInsert(root, 'F');
  bTreeInsert(root, 'H');
  bTreeInsert(root, 'I');
  bTreeInsert(root, 'Q');
  bTreeInsert(root, 'P');
  bTreeInsert(root, 'R');
  bTreeInsert(root, 'A');
  bTreeInsert(root, 'Z');
  bTreeInsert(root, 'W');
  bTreeInsert(root, 'C');
  bTreeInsert(root, 'K');
  cout << bTreeToString(root, "--", 0);
  BTreeNode *node = new BTreeNode();
  int index;
  bTreeSearch(root, 'P', node, index);
  cout << "Search Result:" << endl;
  cout << 'P' << "->" << index;
  if (index != -1)
    cout << ":" << string(node->keys, node->numKeys) << endl;
}
