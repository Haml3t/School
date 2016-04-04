#include <string>
#include "btree.h"

// The default BTreeNode constructor
BTreeNode::BTreeNode() {
    // TODO
}

// The overloaded BTreeNode constructor
BTreeNode::BTreeNode(bool isLeaf, int numKeys) {
    // TODO
}

/*
 The BTreeNode destructor
 Hint: Make sure to release any memory reserved in the heap to avoid memory leaks.
*/
BTreeNode::~BTreeNode() {
    // TODO
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
}

/*
 The BTree insert function
 Hint: Note that root is passed-by-reference in order to accommodate the situations
       in which the BTree height is increased.
*/
void bTreeInsert(BTreeNode *&root, char key) {
    // TODO
}

// The BTree insert non-full function
void bTreeInsertNonfull(BTreeNode *root, char key) {
    // TODO
}

// The BTree split child function
void bTreeSplitChild(BTreeNode *root, int index) {
    // TODO
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
