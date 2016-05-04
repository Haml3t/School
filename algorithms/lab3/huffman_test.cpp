#include <fstream>
#include <iostream>
#include <sstream>
#include "huffman.h"

using namespace std;

const int MAXELEM = 256;

// Parses the test file
void parseFrequencies(string filePath, char *&characters, int *&frequencies, int &length) {
    int rawFrequencies[MAXELEM];
    // Init array to 0s
    for (int i = 0; i < MAXELEM; i++)
	rawFrequencies[i] = 0;
    // Read chars from file
    fstream infile;
    infile.open(filePath.c_str(), ios::in);
    while (!infile.eof())
	rawFrequencies[infile.get()]++;
    // Find total chars
    length = 0;
    for (int i = 0; i < MAXELEM; i++)
	if (rawFrequencies[i] != 0)
	    length++;
    // Init characters and frequencies arrays
    characters = new char[length];
    frequencies = new int[length];
    int j = 0;
    for (int i = 0; i < MAXELEM; i++)
	if (rawFrequencies[i] != 0) {
	    characters[j] = i;
	    frequencies[j++] = rawFrequencies[i];
	}
}

// Renders the frequency data to the given stringstream
void renderFrequencies(stringstream &output, char *characters, int *frequencies, int length) {
    for (int i = 0; i < length; i++)
	output << characters[i] << ": " << frequencies[i] << endl;
}

// Renders the Huffman tree to the given stringstream
void renderHuffmanTree(stringstream &output, HuffmanNode *node, string edgeString, int sepCount) {
    if (node->isLeaf) {
	for (int i = 0; i < sepCount; i++)
	    output << edgeString;
	output << node->frequency << ":" << node->character << endl;
    } else {
	renderHuffmanTree(output, node->right, edgeString, sepCount + 1);
	for (int i = 0; i < sepCount; i++)
	    output << edgeString;
	output << node->frequency << endl;
	renderHuffmanTree(output, node->left, edgeString, sepCount + 1);
    }
}

// Recursively computes the Huffman codes by traversing the huffman tree
void computeHuffmanCodesHelper(HuffmanNode *node, string *codes, string code) {
    if (node->isLeaf)
	codes[(int) node->character] = code;
    else {
	computeHuffmanCodesHelper(node->left, codes, code + "0");
	computeHuffmanCodesHelper(node->right, codes, code + "1");
    }
}

// Computes the Huffman codes
void computeHuffmanCodes(string *&codes, HuffmanNode *huffmanTree, char *characters, int length) {
    string rawCodes[MAXELEM];
    for (int i = 0; i < MAXELEM; i++)
	rawCodes[i] = "";
    computeHuffmanCodesHelper(huffmanTree, rawCodes, "");
    codes = new string[length];
    for (int i = 0; i < length; i++)
	codes[i] = rawCodes[(int) characters[i]];
}

// Renders the Huffman code data to the given stringstream
void renderHuffmanCodes(stringstream &output, char *characters, string *codes, int length) {
    for (int i = 0; i < length; i++)
	output << characters[i] << ": " << codes[i] << endl;
}

// Processes the test file and returns the result
string processTestFile(string filePath, string edgeString) {
    stringstream output;
    char *characters;
    int *frequencies;
    int length;
    string *codes;
    parseFrequencies(filePath, characters, frequencies, length);
    HuffmanNode **nodes = genHuffmanNodes(characters, frequencies, length);
    HuffmanNode *huffmanTree = genHuffmanTree(nodes, length);
    computeHuffmanCodes(codes, huffmanTree, characters, length);
    output << "Frequencies:" << endl;
    renderFrequencies(output, characters, frequencies, length);
    output << "Huffman Tree:" << endl;
    renderHuffmanTree(output, huffmanTree, edgeString, 0);
    output << "Huffman Codes:" << endl;
    renderHuffmanCodes(output, characters, codes, length);
    return output.str();
}

int main(int argc, char *argv[]) {
  cout << processTestFile(argv[1], "--");
  return 0;
}
