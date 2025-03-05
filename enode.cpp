/*
Henry Xu
C++
11/13/24
dNode.cpp
*/
#include <iostream>
#include <cstring>
#include "enode.h"

using namespace std;

eNode::eNode(dNode* tempnode) {
    storednode = tempnode; // set storednode as node pointer
    nextnode = NULL;
}

eNode::~eNode(){//set nextnode and storednode to null
    nextnode = NULL;
    storednode = NULL;
}

dNode* eNode::getnode(){//getting the stored node
    return storednode;
}

void eNode::setnode(dNode* tempnode){//setting node
    storednode = tempnode;
}

void eNode::setNext(eNode* tempnode){
    nextnode = tempnode; //setting the next node
}

eNode* eNode::getNext(){
  return nextnode;//returning the next node
}
