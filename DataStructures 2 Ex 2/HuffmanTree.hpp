//
//  HuffmanTree.hpp
//  DataStructures 2 Ex 2
//
//  Created by Jacques Benzakein on 11/6/18.
//  Copyright © 2018 Q Technologies. All rights reserved.
//

#ifndef HuffmanTree_hpp
#define HuffmanTree_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "Node.hpp"
using namespace std;

class HuffmanTree{
public:
    Node root;
    list<Node*> nodeList;
    
    int frequencyList[256] = {0};
    string encodingList[256] = {""};
    
    HuffmanTree(string text);
    
    void encodeTheTree(Node node, string encodingSoFar);
    
};

#endif /* HuffmanTree_hpp */
