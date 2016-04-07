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
  // cout << root->keys[1] << endl;
  // cout << root->numKeys << endl;
  // cout << root->children[1]->isLeaf << endl;
  // cout << root->children[1]->keys[1] << endl;
  // cout << root->children[1]->keys[2] << endl;
  // cout << root->children[1]->keys[3] << endl;
  // cout << root->children[1]->keys[4] << endl;
  // cout << root->children[1]->keys[5] << endl;
  // cout << root->keys[2] << endl;
  // cout << root->keys[3] << endl;
  // cout << root->keys[4] << endl;
  // cout << root->keys[5] << endl;
  // cout << root->keys[6] << endl;
  // cout << root->keys[7] << endl;
  cout << bTreeToString(root, "--", 0) << endl;
}
