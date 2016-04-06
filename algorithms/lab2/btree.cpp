#include <string>
#include "btree.h"

// The default BTreeNode constructor
BTreeNode::BTreeNode() {
    // TODO
  bool isLeaf = true;
  int numkeys = 0;
  char keys[MAXSIZE];
  BTreeNode *children[MAXSIZE + 1];
}

// The overloaded BTreeNode constructor
BTreeNode::BTreeNode(bool isLeaf, int numKeys) {
    // TODO
  isLeaf = isLeaf;
  numKeys = numKeys;
  char keys[MAXSIZE];
  BTreeNode *children[MAXSIZE + 1];
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
  int i = 1;
  while (i <= root->numKeys && key > root->keys[i]) {
    i = i + 1;
  }
  if (i <= root->numKeys && key == root->keys[i]) {
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
  BTreeNode *newRoot = root;
  if (newRoot->numKeys == (2 * T - 1)) {
      BTreeNode *s = new BTreeNode();
      root = s;
      s->isLeaf = false;
      s->numKeys = 0;
      s->children[1] = newRoot;
      bTreeSplitChild(s, 1);
      bTreeInsertNonfull(s, key);
    }
  else {
    bTreeInsertNonfull(newRoot, key);
  }
}

// The BTree insert non-full function
void bTreeInsertNonfull(BTreeNode *root, char key) {
    // TODO
  int i = root->numKeys;
  if (root->isLeaf) {
    while (i >= 1 && key <= root->keys[i]) {
      root->keys[i+1] = root->keys[i];
      i = i - 1;
    }
    root->keys[i + 1] = key;
    root->numKeys = root->numKeys + 1;
  }
  else {
    while (i >= 1 && key < root->keys[i]) {
      i = i - 1;
    }
    i = i + 1;
    if (root->children[i]->numKeys == (2 * T - 1)) {
      bTreeSplitChild(root, i);
      if (key > root->keys[i]) {
	i = i + 1;
      }
    }
    bTreeInsertNonfull(root->children[i], key);
  }
}

// The BTree split child function
void bTreeSplitChild(BTreeNode *root, int index) {
    // TODO
  BTreeNode *z = new BTreeNode;
  BTreeNode *y = root->children[index];
  z->isLeaf = y->isLeaf;
  z->numKeys = T - 1;
  int j = 0;
  for (j = 1; T - 1; j = j++) {
    z->keys[j] = y->keys[j+T];
  }
  if (!y->isLeaf) {
    for (j = 1; T; j++) {
      z->children[j] = y->children[j+T];
    }
  }
  y->numKeys = T - 1;
  for (j = root->numKeys + 1; index + 1; j--) {
    root->children[j+1] = root->children[j];
  }
  root->children[index+1] = z;
  for (j = root->numKeys; index; j--) {
    root->keys[j+1] = root->keys[j];
  }
  root->keys[index] = y->keys[T];
  root->numKeys = root->numKeys + 1;
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
    for (int i = 0; i < level; i++)
	edge += edgeString;
    if (node->isLeaf) {
	for (int i = node->numKeys - 1; i >= 0; i--) {
	    output += edge + node->keys[i] + "\n";
	}
    } else {
	output += bTreeToString(node->children[node->numKeys], edgeString, level + 1);
	for (int i = node->numKeys - 1; i >= 0; i--) {
	    output += edge + node->keys[i] + "\n";
	    output += bTreeToString(node->children[i], edgeString, level + 1);
	}
    }
    return output;
}
