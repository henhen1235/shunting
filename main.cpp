#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void push(char nchar, Node*& stastart);
char peak(Node* stastart);
void pop(Node*& stastart);
void enqueue(char nchar, Node*& questart);
void dequeue(Node*& questart);
void destroy(Node *& stastart);

int main(){
  Node* questart = nullptr;
  Node* stastart = nullptr;
  while(true){
  int num;
  cin >> num;
  if(num == 1){
    char tempchar;
    cin >> tempchar;
    push(tempchar, stastart);
  }
  if(num == 2){
    cout << peak(stastart) << endl;
  }
  if(num == 3){
    pop(stastart);
  }
  if(num == 4){
    while (stastart != NULL){
      Node* temp = stastart;
      stastart = stastart->getNext();
      delete temp;
    }
    break;
  }
  if(num == 5){
    Node* tempstastart = stastart;
    while(tempstastart != NULL){
      cout << tempstastart->getchar();
      tempstastart = tempstastart->getNext();
    }
  }
}
  return 0;
}

void push(char nchar, Node*& stastart){
  /*
  if(stastart == nullptr){
    Node* newnode = new Node(nchar);
    stastart = newnode;
    return;
  }
  Node* tempnode = stastart; 
  while(tempnode->getNext() != NULL){
    tempnode = tempnode->getNext();
  }
  Node* newnode = new Node(nchar);
  tempnode->setNext(newnode);
*/
Node* newnode = new Node(nchar);
newnode->setNext(stastart);
stastart = newnode;
  }

char peak(Node* stastart){
  if(stastart == nullptr){
    return '\0' ;
  }
  return stastart->getchar();
}

void pop(Node*& stastart){
  if(stastart == nullptr){
    return;
  }
  Node* tempnode = stastart;
  stastart = stastart->getNext();
  delete tempnode;
  /*
  if(stastart->getNext() == nullptr){
    delete stastart;
    stastart = nullptr;
    return;
  }
  Node* tempnode = stastart;
  while(tempnode->getNext()->getNext() != NULL){
    tempnode = tempnode->getNext();
  }
  Node* tempnode2 = tempnode->getNext();
  delete tempnode2;
  tempnode->setNext(NULL);
*/
  }
