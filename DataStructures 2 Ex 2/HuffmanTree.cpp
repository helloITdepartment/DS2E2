//
//  HuffmanTree.cpp
//  DataStructures 2 Ex 2
//
//  Created by Jacques Benzakein on 11/6/18.
//  Copyright © 2018 Q Technologies. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>
#include "HuffmanTree.hpp"
using namespace std;


bool isLarger(Node* x, Node* y){
    return x->frequency<y->frequency;
}

HuffmanTree::HuffmanTree(string text){
    root = Node(' ', 0);
    
    //Read in all the letters
    for(char letter:text){
        frequencyList[letter]++;
    }
    
    //Turn them all into nodes
    for(int i = 0; i<256; i++){
        int freq = frequencyList[i];
        if(freq > 0){
            Node* nodeToPush = new Node(char(i), freq);
//            cout << (char) i << ":  " << freq << endl;
            nodeList.push_back(nodeToPush);
        }
    }
    
    int pass = 0;
    
    while(nodeList.size() > 1){
        
        nodeList.sort(isLarger);
        
        cout<< ++pass << ": ";
        
        list<Node * > :: iterator itr8r;
        for(itr8r = nodeList.begin(); itr8r != nodeList.end(); itr8r++){
            cout << (*itr8r)->value;
        }
        cout<< endl;
        
        Node min = *nodeList.front();
        nodeList.remove(nodeList.front());
        Node secondMin = *nodeList.front();
        nodeList.remove(nodeList.front());
        
        //Join them together and put it back in
        Node nodeToPush = Node('*', (min.frequency + secondMin.frequency));
        
        nodeToPush.rightChild = &min;
        nodeToPush.leftChild = &secondMin;
        nodeList.push_back(&nodeToPush);
        
/*        //Find the least fequent character in the list
        list<Node * > :: iterator itr8r;
        for(itr8r = nodeList.begin(); itr8r != nodeList.end(); itr8r++){
            cout << (*itr8r)->value;
            if((*itr8r)->frequency < min.frequency){
                nodeList.push_back(&min);
                min = *(*itr8r);
                nodeList.remove(*itr8r);
            }
        }
        
        //Find the second least frequent
        secondMin = *nodeList.front();
        nodeList.remove(nodeList.front());
        if(nodeList.size() >0){
            list<Node * > :: iterator itr8r;
            for(itr8r = nodeList.begin(); itr8r != nodeList.end(); itr8r++){
                if((*itr8r)->frequency < secondMin.frequency){
                    nodeList.push_back(&secondMin);
                    secondMin = *(*itr8r);
                    nodeList.remove(*itr8r);
                }
            }
        }*/
        
        
/*        For testing
        cout << min.value << endl;
        for(itr8r = nodeList.begin(); itr8r != nodeList.end(); itr8r++){
            cout << (*itr8r)->value;
        } */
    }
    
//    cout << "Done\n";
    
    root = *nodeList.front();
    
    encodeTheTree(root, "");
};

void HuffmanTree::encodeTheTree(Node node, string encodingSoFar){
    if(node.isLeaf()){
        node.encoding = encodingSoFar;
        encodingList[node.value] = encodingSoFar;
        cout << "Just encoded " << node.value << " with encoding " << encodingSoFar << endl;
    }else{
        //cout << "else";
        encodeTheTree(*(node.leftChild), (encodingSoFar + "0"));
        encodeTheTree(*(node.rightChild), (encodingSoFar + "1"));
    }
};



