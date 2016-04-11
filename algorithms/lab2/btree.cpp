#include "btree.h"
#include <string>

#include <iostream>
#include <ostream>

// The default BTreeNode constructor
BTreeNode::BTreeNode() {
  // TODO
  this->isLeaf = true;
  this->numKeys = 0;
}

// The overloaded BTreeNode constructor
BTreeNode::BTreeNode(bool isLeaf, int numKeys) {
  // TODO
  this->isLeaf = isLeaf;
  this->numKeys = numKeys;
}

/*
  The BTreeNode destructor
  Hint: Make sure to release any memory reserved in the heap to avoid memory leaks.
*/
BTreeNode::~BTreeNode() {
  // TODO
  // delete isLeaf;
  // delete numKeys;
  delete[] keys;
  delete[] children;
}

/*
  The BTree search function
  Hint: Notice there are two return arguments, 1) returnNode, 2) returnIndex.
  If the given key does not exist in the BTree, you should return the following.
  returnNode = NULL
  returnIndex = -1
*/
void bTreeSearch(BTreeNode *root, char key, BTreeNode *&returnNode, int &returnIndex) {
  // TODO
  int i = 0;
  while (i < root->numKeys && key > root->keys[i]) {
    i++;
  }
  if (i < root->numKeys && key == root->keys[i]) {
    returnNode = root;
    returnIndex = i;
    return;
  }
  else if (root->isLeaf) {
    returnNode = NULL;
    returnIndex = -1;
    return;
  }
  else {
    bTreeSearch(root, key, returnNode, returnIndex);
  }
}

/*

  The BTree insert function
  Hint: Note that root is passed-by-reference in order to accommodate the situations
  in which the BTree height is increased.
*/
void bTreeInsert(BTreeNode *&root, char key) {
  // TODO
  BTreeNode *oldRoot = root;
  if (oldRoot->numKeys == (2 * T - 1)) {
    BTreeNode *s = new BTreeNode();
    root = s;
    s->isLeaf = false;
    s->numKeys = 0;
    s->children[0] = oldRoot;
    bTreeSplitChild(s, 0);
    bTreeInsertNonfull(s, key);
  }
  else {
    bTreeInsertNonfull(oldRoot, key);
  }
}

// The BTree insert non-full function
void bTreeInsertNonfull(BTreeNode *root, char key) {
  int i = root->numKeys - 1;
  if (root->isLeaf) {
    while (i >= 0 && (key <= root->keys[i])) {
      root->keys[i+1] = root->keys[i];
      i--;
    }

    root->keys[i + 1] = key;
    root->numKeys = root->numKeys + 1;
  }
  else {
    while (i >= 0 && key <= root->keys[i]) {
      i--;
    }
    i++;
    if (root->children[i]->numKeys == (2 * T - 1)) {
      bTreeSplitChild(root, i);
      if (key > root->keys[i]) {
	i++;
      }
    }
    bTreeInsertNonfull(root->children[i], key);
  }
}

// The BTree split child function
void bTreeSplitChild(BTreeNode *root, int index) {
  // TODO
  BTreeNode *child2 = new BTreeNode();
  BTreeNode *child1 = root->children[index];
  child2->isLeaf = child1->isLeaf;
  child2->numKeys = T - 1;
  int j;
  for (j = 0; j < (T - 1); j++) {
    child2->keys[j] = child1->keys[j+T];
  }
  if (!child1->isLeaf) {
    for (j = 0; j < T; j++) {
      child2->children[j] = child1->children[j+T];
    }
  }
  child1->numKeys = T - 1;
  for (j = root->numKeys; j > index; j--) {
    root->children[j+1] = root->children[j];
  }
  root->children[index+1] = child2;
  for (j = root->numKeys; j > index; j--) { // awdaw
    root->keys[j+1] = root->keys[j];
  }
  root->keys[index] = child1->keys[T - 1];
  root->numKeys++;
}

/*
  The BTree delete function
  Hints: 1) Make sure to "delete" BTreeNode objects appropriately when they
  are no longer needed.
  2) When you have a choice to make, ALWAYS go from left to right.
  Otherwise, your function may produce a different btree than
  the one constructed in the grading program.
  3) Note that root is passed-by-reference in order to accommodate the
  situations in which the BTree height is decreased.
  4) Make sure to handle the case when the given key does not exist in BTree.
*/
void bTreeDelete(BTreeNode *&root, char key) {
  // TODO
}


// Converts a BTree to a human-readable string.
string bTreeToString(BTreeNode *node, string edgeString, int level) {
  string output = "";
  string edge = "";
  for (int i = 0; i < level; i++) {
    edge += edgeString;
  }
  if (node->isLeaf) {
    for (int i = node->numKeys - 1; i >= 0; i--) {
      output += edge + node->keys[i] + "\n";
    }
  }
  else {
    output += bTreeToString(node->children[node->numKeys], edgeString, level + 1);
    for (int i = node->numKeys - 1; i >= 0; i--) {
      output += edge + node->keys[i] + "\n";
      output += bTreeToString(node->children[i], edgeString, level + 1);
    }
  }
  return output;
}
