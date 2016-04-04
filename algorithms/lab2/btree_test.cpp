#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "btree.h"

using namespace std;

// Processes the test file and returns the result.
string processTestFile(string filePath, string edgeString) {
    BTreeNode *root = new BTreeNode();
    string output = "";
    fstream infile;
    infile.open(filePath.c_str(), ios::in);
    string line;
    while (!infile.eof()) {
        getline(infile, line);
        switch (line[0]) {
            case '+':
                bTreeInsert(root, line[1]);
                break;
            case '-':
                bTreeDelete(root, line[1]);
                break;
            case '?': {
                BTreeNode *node;
                int index;
                bTreeSearch(root, line[1], node, index);
                stringstream outputStringStream;
                outputStringStream << "Search Result:" << endl;
                outputStringStream << line[1] << "->" << index;
                if (index != -1)
                    outputStringStream << ":" << string(node->keys, node->numKeys);
                outputStringStream << endl;
                output += outputStringStream.str();
                break;
            }
            case '#':
                stringstream outputStringStream;
                outputStringStream << "BTree:" << endl;
                outputStringStream << bTreeToString(root, edgeString, 0);
                output += outputStringStream.str();
                break;
        }
    }
    infile.close();
    return output;
}

int main(int argc, char *argv[]) {
    cout << processTestFile(argv[1], "--");
    return 0;
}
