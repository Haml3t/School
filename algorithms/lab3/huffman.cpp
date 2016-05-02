#include <cstddef>
#include "huffman.h"

// ---------------------------------------------------------------------------------------------
// Huffman code related
// ---------------------------------------------------------------------------------------------

// The HuffmanNode constructor for leaf nodes
HuffmanNode::HuffmanNode(char character, int frequency) {
    // TODO
}

// The HuffmanNode constructor for internal nodes
HuffmanNode::HuffmanNode(int frequency, HuffmanNode *left, HuffmanNode *right) {
    // TODO
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
    // TODO
    return NULL;
}

/*
 Creates the Huffman tree reusing the given HuffmanNodes.

 nodes: an array of HuffmanNode*
 length: the length of nodes array

 returns: the pointer to the root of the huffman tree
*/
HuffmanNode *genHuffmanTree(HuffmanNode **nodes, int length) {
    // TODO
    return NULL;
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
    for (int i = 0; i < length; i++)
        this->heapNodes[i] = nodes[i];
    buildMinHeap();
}

// Exchanges the HuffmanNode pointers at the given indices of heapNodes array
void MinHeap::exchange(int firstIndex, int secondIndex) {
    // TODO
}

// Applies the minHeapify algorithm starting from the given index
void MinHeap::minHeapify(int index) {
    // TODO
}

// Converts the heapNodes array into a heap
void MinHeap::buildMinHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        minHeapify(i);
}

// Removes the minimum element from the heap and returns it
HuffmanNode *MinHeap::extractMin() {
    // TODO
    return NULL;
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
