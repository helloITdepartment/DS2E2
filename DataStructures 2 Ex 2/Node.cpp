//
//  Node.cpp
//  DataStructures 2 Ex 2
//
//  Created by Jacques Benzakein on 11/6/18.
//  Copyright © 2018 Q Technologies. All rights reserved.
//

#include "Node.hpp"


Node::Node(){
    value = NULL;
    frequency = 0;
    leftChild = NULL;
    rightChild = NULL;
};

Node::Node(char val, int freq){
    value = val;
    frequency = freq;
    leftChild = NULL;
    rightChild = NULL;
};

bool Node::isLeaf(){
    return (leftChild == NULL && rightChild == NULL);
};
