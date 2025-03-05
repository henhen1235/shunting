/*
Henry Xu
C++
11/13/24
Node.cpp
*/
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(char nstudent) {
  stored = nstudent; // set stored as char
  nextnode = NULL;//set next node to null for now
}

Node::~Node(){//set char and next node to null
  nextnode = NULL;
}

void Node::setchar(char nchar){//set char
  stored = nchar;
}

char Node::getchar(){// return char
    return stored;
}

void Node::setNext(Node* newnode){
  nextnode = newnode; //setting the next node up
}

Node* Node::getNext(){
  return nextnode;//returning the node
}
