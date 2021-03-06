// David Sugarman 5364
#include <cstddef>
#include "huffman.h"
#include <iostream>
using namespace std;

// ---------------------------------------------------------------------------------------------
// Huffman code related
// ---------------------------------------------------------------------------------------------

// The HuffmanNode constructor for leaf nodes
HuffmanNode::HuffmanNode(char character, int frequency) {
  this->character = character;
  this->frequency = frequency;
  this->isLeaf = true;
  this->left = NULL;
  this->right = NULL;
}

// The HuffmanNode constructor for internal nodes
HuffmanNode::HuffmanNode(int frequency, HuffmanNode *left, HuffmanNode *right) {
  this->character = character;
  this->frequency = frequency;
  this->isLeaf = false;
  this->left = left;
  this->right = right;
}

/*
 Creates an array of HuffmanNodes (more specifically, pointers to HuffmanNodes)
 based on the given character-frequency pairs.

 characters: an array of char
 frequencies: an array of int
 length: the length of characters and frequencies arrays

 returns: an array of HuffmanNode*

 Note: For 0 <= i < length, the frequency of the character characters[i]
       is found at frequencies[i].
*/
HuffmanNode **genHuffmanNodes(char *characters, int *frequencies, int length) {
  HuffmanNode **heapNodes = new HuffmanNode*[length];
  for (int i = 0; i < length; i++) {
    heapNodes[i] = new HuffmanNode(characters[i], frequencies[i]);
  }
    return heapNodes;
}

/*
 Creates the Huffman tree reusing the given HuffmanNodes.

 nodes: an array of HuffmanNode*
 length: the length of nodes array

 returns: the pointer to the root of the huffman tree
*/
HuffmanNode *genHuffmanTree(HuffmanNode **nodes, int length) {
  MinHeap *queue = new MinHeap(nodes, length);
  for (int i = 1; i <= length - 1; i++) {
    HuffmanNode *x = queue->extractMin();
    HuffmanNode *y = queue->extractMin();
    HuffmanNode *z = new HuffmanNode(x->frequency + y->frequency, x, y);
    queue->insert(z);
  }
  return queue->extractMin();
}

// ---------------------------------------------------------------------------------------------
// Min heap related
// ---------------------------------------------------------------------------------------------

// Helper functions for heap
int left(int index) {
    return (index + 1) * 2 - 1;
}

int right(int index) {
    return (index + 1) * 2;
}

int parent(int index) {
    return (index + 1) / 2 - 1;
}

// MinHeap constructor
MinHeap::MinHeap(HuffmanNode **nodes, int length) {
    heapSize = length;
    this->heapNodes = new HuffmanNode *[length];
    for (int i = 0; i <= length-1; i++)
      this->heapNodes[i] = nodes[i];
    buildMinHeap();
}

// Exchanges the HuffmanNode pointers at the given indices of heapNodes array
void MinHeap::exchange(int firstIndex, int secondIndex) {
  HuffmanNode *dummy = new HuffmanNode(heapNodes[firstIndex]->character, heapNodes[firstIndex]->frequency);
  dummy->right = heapNodes[firstIndex]->right;
  dummy->left = heapNodes[firstIndex]->left;
  dummy->isLeaf = heapNodes[firstIndex]->isLeaf;
  // 1) copy secondIndex stuff into firstIndex
  heapNodes[firstIndex]->right = heapNodes[secondIndex]->right;
  heapNodes[firstIndex]->left = heapNodes[secondIndex]->left;
  heapNodes[firstIndex]->isLeaf = heapNodes[secondIndex]->isLeaf;
  // 2) set appropriate pointer of parent(firstIndex) to secondIndex
  if (heapNodes[firstIndex] == heapNodes[parent(firstIndex)]->right) {
      heapNodes[parent(firstIndex)]->right = heapNodes[secondIndex];
    }
  else if (heapNodes[firstIndex] == heapNodes[parent(firstIndex)]->left) {
    heapNodes[parent(firstIndex)]->left = heapNodes[secondIndex];
    }
  else {
    cout << "Exchange error: invalid parent/child relationship" << endl;
  }
  // now firstIndex is done
  // 3) copy dummy stuff into secondIndex
  heapNodes[secondIndex]->right = dummy->right;
  heapNodes[secondIndex]->left = dummy->left;
  heapNodes[secondIndex]->isLeaf = dummy->isLeaf;
  // 4) set appropriate pointer of parent()
  if (heapNodes[secondIndex] == heapNodes[parent(secondIndex)]->right) {
    heapNodes[parent(secondIndex)]->right = heapNodes[firstIndex];
    }
  else if (heapNodes[secondIndex] == heapNodes[parent(secondIndex)]->left) {
    heapNodes[parent(secondIndex)]->left = heapNodes[firstIndex];
    }
  else {
    cout << "Exchange error: invalid parent/child relationship" << endl;
  }
  // now firstIndex is done
}

// Applies the minHeapify algorithm starting from the given index
void MinHeap::minHeapify(int index) {
  int l = left(index);
  int r = right(index);
  int smallest = 0;
  if ((l <= this->heapSize-1) && (this->heapNodes[l] < this->heapNodes[index])) {
    smallest = l;
  }
  else {
    smallest = index;
  }
  if ((r <= this->heapSize-1) && (this->heapNodes[r] < this->heapNodes[smallest])) {
    smallest = r;
  }
  if (smallest != index) {
    exchange(index, smallest);
    minHeapify(smallest);
  }
}

// Converts the heapNodes array into a heap
void MinHeap::buildMinHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
	minHeapify(i);
}

// Removes the minimum element from the heap and returns it
HuffmanNode *MinHeap::extractMin() {
  if (heapSize < 1) {
    cout << "Error: heap underflow" << endl;
  }
  HuffmanNode *min = this->heapNodes[0];
  this->heapNodes[0] = this->heapNodes[heapSize-1];
  heapSize--;
  minHeapify(0);
    return min;
}

// Inserts a new HuffmanNode to the heap
void MinHeap::insert(HuffmanNode *node) {
    heapSize++;
    int i = heapSize - 1;
    heapNodes[i] = node;
    while (i > 0 && *heapNodes[parent(i)] > *heapNodes[i]) {
	exchange(i, parent(i));
	i = parent(i);
    }
}
