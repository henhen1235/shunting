/*
Henry Xu
C++
11/13/24
Node.h
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
 public:
  Node(char nstudent);//create a node with a char in it
  ~Node();//destuctor
  char getchar();//getting the char
  void setchar(char nchar);//setting the char
  void setNext(Node* newnode);//setting the next node
  Node* getNext();//getting the next node
 private:
  char stored;//char
  Node* nextnode;//node pointer
};
#endif
