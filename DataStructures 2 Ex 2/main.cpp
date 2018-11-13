//
//  main.cpp
//  DataStructures 2 Ex 2
//
//  Created by Jacques Benzakein on 11/5/18.
//  Copyright © 2018 Q Technologies. All rights reserved.
//

#include <iostream>
#include "HuffmanTree.hpp"
using namespace std;

int main() {
    char input;
    string text, length, inOrderReading, huffmanTreeRepresentation;
    HuffmanTree* tree;
    cout << "Hello, user! \nPlease enter \n1 to encode text, \n2 to decode text, or\n3 to exit" << endl;
    cin >> input;
    while(input != '3'){
        switch (input) {
            case '1':
                cout << "Enter the text to be encoded" << endl;
                cin >> text;
                tree = new HuffmanTree(text);
                break;
            case '2':
                cout << "Please enter the number of characters: ";
                cin >> length;
                cout << "Please enter the characters inOrder: ";
                cin >> inOrderReading;
                cout << "Please enter the representation of the tree you're using: ";
                cin  >> huffmanTreeRepresentation;
                cout << "Please enter the text to be decoded: ";
                cin >> text;
                break;
            case '3':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Sorry, that's not a valid input. Remember, enter \n1 to encode text, \n2 to decode text, or\n3 to exit" << endl;
                break;
        }
        cin >> input;
    }
    return 0;
}
