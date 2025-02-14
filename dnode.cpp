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
  stored = nstudent; // set student as student pointer
  rightnode = NULL;//set next node to null for now
  leftnode = NULL;
}

dNode::~dNode(){//set student and next node to null
  rightnode = NULL;//keep in mind that since the code doens't actually destruct student you need to do that also manually in main.cpp
  leftnode = NULL;
}

void dNode::setchar(char nchar){
  stored = nchar;
}

char dNode::getchar(){// if the student exists then return it
    return stored;
}

void dNode::setRight(dNode* newnode){
  rightnode = newnode; //setting the next node up
}

void dNode::setLeft(dNode* newnode){
  leftnode = newnode; //setting the next node up
}

dNode* dNode::getRight(){
  return rightnode;//returning the node
}

dNode* dNode::getLeft(){
  return leftnode;//returning the node
}
