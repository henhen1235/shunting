/*
Henry Xu
C++
11/13/24
dNode.cpp
*/
#include <iostream>
#include <cstring>
#include "dnode.h"

using namespace std;

dNode::dNode(char nstudent) {
  stored = nstudent; // set char as stored
  rightnode = NULL;//set right node to null for now
  leftnode = NULL;//set left node to null for now
}

dNode::~dNode(){//destruct
  rightnode = NULL;
  leftnode = NULL;
}

void dNode::setchar(char nchar){// setting char
  stored = nchar;
}

char dNode::getchar(){//getting char
    return stored;
}

void dNode::setRight(dNode* newnode){
  rightnode = newnode; //setting the right node up
}

void dNode::setLeft(dNode* newnode){
  leftnode = newnode; //setting the left node up
}

dNode* dNode::getRight(){
  return rightnode;//returning the right node
}

dNode* dNode::getLeft(){
  return leftnode;//returning the left node
}
