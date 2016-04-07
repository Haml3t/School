#ifndef BTREE_H_
#define BTREE_H_
#define T 3
#define MAXSIZE (2 * T) - 1
#define MINSIZE T - 1

using namespace std;

// The BTree node struct
struct BTreeNode {
    bool isLeaf;
    int numKeys;
    char keys[MAXSIZE];
    BTreeNode *children[MAXSIZE + 1];

    BTreeNode();

    BTreeNode(bool, int);

    ~BTreeNode();
};

// BTree functions
void bTreeSearch(BTreeNode *, char, BTreeNode *&, int &);

void bTreeInsert(BTreeNode *&, char);

void bTreeInsertNonfull(BTreeNode *, char);

void bTreeSplitChild(BTreeNode *, int);

void bTreeDelete(BTreeNode *&, char);

string bTreeToString(BTreeNode *, string, int);

#endif /* BTREE_H_ */
