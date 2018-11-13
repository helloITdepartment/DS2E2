//
//  Node.hpp
//  DataStructures 2 Ex 2
//
//  Created by Jacques Benzakein on 11/6/18.
//  Copyright © 2018 Q Technologies. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Node{
public:
    char value;
    int frequency;
    Node* leftChild;
    Node* rightChild;
    string encoding;
    
    Node();
    Node(char val, int freq);
    
    bool isLeaf();
};

#endif /* Node_hpp */
