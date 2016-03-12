#include <fstream>
#include <iostream>
#include <sstream>
#include "sort.h"

using namespace std;

/*
Reads a line from the given file object and parses that line into
an array of integers. The first number in the line is assumed to
represent the length of the resulting array.
*/
void getNumbersFromFile(fstream &infile, int *&numbers, int &length) {
    string line;
    getline(infile, line);
    istringstream numbersStream(line);
    numbersStream >> length;
    numbers = new int[length];
    for (int i = 0; i < length; i++)
        numbersStream >> numbers[i];
}

//Processes the test file and returns the result.
string processTestFile(string filePath, string edge) {
    string output = "";
    fstream infile;
    infile.open(filePath.c_str(), ios::in);
    string line;
    while (!infile.eof()) {
        getline(infile, line);
        switch (line[0]) {
            case 'm': {
                int *numbers1, *numbers2, length1, length2;
                getNumbersFromFile(infile, numbers1, length1);
                getNumbersFromFile(infile, numbers2, length2);
                LinkedListNode *list1 = createLinkedList(numbers1, length1);
                LinkedListNode *list2 = createLinkedList(numbers2, length2);
                LinkedListNode *mergedList = mergeSortedLinkedLists(list1, list2);
                output += "merged linked list:\n";
                output += linkedListToString(mergedList, edge) + "\n";
                break;
            }
            case 's': {
                int *numbers, length;
                getNumbersFromFile(infile, numbers, length);
                LinkedListNode *list = createLinkedList(numbers, length);
                LinkedListNode *sortedList = sortLinkedList(list);
                output += "sorted linked list:\n";
                output += linkedListToString(sortedList, edge) + "\n";
                break;
            }
            case 't':
                int *numbers, length, startNodePosition;
                getNumbersFromFile(infile, numbers, length);
                LinkedListNode *list = createLinkedList(numbers, length);
                getline(infile, line);
                istringstream startNodePositionStream(line);
                startNodePositionStream >> startNodePosition;
                LinkedListNode *startNode = list;
                while (startNodePosition--)
                    startNode = startNode->next;
                output += "linked list before sorting:\n";
                output += linkedListToString(startNode, edge) + "\n";
                sortLinkedList(list);
                output += "linked list after sorting:\n";
                output += linkedListToString(startNode, edge) + "\n";
                break;
        }
    }
    infile.close();
    return output;
}

int main(int argc, char *argv[]) {
    cout << processTestFile(argv[1], " -> ");
    return 0;
}
