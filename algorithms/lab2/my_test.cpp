#include <string>
#include "btree.h"
#include <iostream>
#include <ostream>

using namespace std;

int main() {
  BTreeNode *root = new BTreeNode(); // create empty BTree
  bTreeInsert(root, "D");
  bTreeInsert(root, "L");
  bTreeInsert(root, "J");
  cout << bTreeToString(root, "--", 0) << endl;
}
