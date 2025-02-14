/*
Henry Xu
C++
11/13/24
dNode.h
*/
#ifndef DNODE_H
#define DNODE_H
#include <iostream>

using namespace std;

class dNode{
 public:
  dNode(char nstudent);//create a node with a student pointer in it
  ~dNode();//destuctor
  char getchar();//getting the student
  void setchar(char nchar);
  void setRight(dNode* newnode);//setting the next node
  void setLeft(dNode* newnode);//setting the next node
  dNode* getRight();//getting the next node
  dNode* getLeft();//getting the next node
 private:
  char stored;//student pointer
  dNode* rightnode;//node pointer
  dNode* leftnode;
};
#endif