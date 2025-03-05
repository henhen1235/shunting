/*
Henry Xu
C++
11/13/24
eNode.h
*/
#ifndef ENODE_H
#define ENODE_H
#include "dnode.h"
#include <iostream>

using namespace std;

class eNode{
 public:
  eNode(dNode* tempnode);//create a node with a node pointer in it
  ~eNode();//destuctor
  dNode* getnode();//getting the node
  void setnode(dNode* tempnode);
  void setNext(eNode* tempnode);//setting the next node
  eNode* getNext();//getting the next node
 private:
  eNode* nextnode;//node pointer
  dNode* storednode;
};
#endif