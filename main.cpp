#include <iostream>
#include <cstring>
#include "node.h"
#include "dnode.h"
using namespace std;

void push(char nchar, Node*& stastart);
char peak(Node* stastart);
void pop(Node*& stastart);
void enqueue(char nchar, Node*& questart);
void dequeue(Node*& questart);
void destroy(Node *& stastart);
void pushd(dNode*& nchar, dNode*& stastart);
dNode* peakd(dNode* stastart);
void popd(dNode*& stastart);
void destroyd(dNode *& stastart);
void infix(dNode* root);

int main(){
  Node* endque = nullptr;
  Node* midstack = nullptr;
  dNode* finalstack = nullptr;
  dNode* finalstack2 = nullptr;
  dNode* treehead = nullptr;
  char in[50];
  cout << endl << "What would you like to input?(It cannot be longer then 50 and no spaces): ";
  cin >> in;
  int x = 0;
  while(in[x] != '\0'){
    char tempchar = in[x];
    if(tempchar == '0' || tempchar == '1' || tempchar == '2' || tempchar == '3' || tempchar == '4' || tempchar == '5' || tempchar == '6' || tempchar == '7' || tempchar == '8' || tempchar == '9'){
      enqueue(tempchar, endque);
      x++;
    }

    else if(tempchar == '+' || tempchar == '-'){
      while(peak(midstack) == '+' || peak(midstack) == '-' || peak(midstack) == '/' || peak(midstack) == '*' || peak(midstack) == '^'){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      push(tempchar, midstack);
      x++;
    }

    else if(tempchar == '*' || tempchar == '/'){
      while(peak(midstack) == '/' || peak(midstack) == '*' || peak(midstack) == '^'){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      push(tempchar, midstack);
      x++;
    }

    else if(tempchar == '^'){
      while(peak(midstack) == '^'){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      push(tempchar, midstack);
      x++;
    }

    else if(tempchar == '('){
      push(tempchar, midstack);
      x++;
    }
    else if(tempchar == ')'){
      while(peak(midstack) != '(' ){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      pop(midstack);
      x++;
    }
    else{
      cout << "error" << endl;
      break;
    }
  }
  
  while(midstack != nullptr) {
    enqueue(peak(midstack), endque);
    pop(midstack);
  }
  cout << endl;
  Node* tempstastart = endque;
    while(tempstastart != NULL){
      cout << tempstastart->getchar();
      tempstastart = tempstastart->getNext();
    }
    cout << endl;
    while(endque != NULL){
      char tempchar = endque->getchar();
      cout << tempchar << endl;
      if(tempchar == '0' || tempchar == '1' || tempchar == '2' || tempchar == '3' || tempchar == '4' || tempchar == '5' || tempchar == '6' || tempchar == '7' || tempchar == '8' || tempchar == '9'){
	dNode* doubnode = new dNode(tempchar);
	cout << "num" << endl;
	doubnode->setLeft(NULL);
        doubnode->setRight(NULL);
	pushd(doubnode, finalstack);
	endque = endque->getNext();
      }
      else{
	dNode* rightNode = peakd(finalstack);
	cout << "right:" << rightNode->getchar() << endl;
        popd(finalstack);
        dNode* leftNode = peakd(finalstack);
	cout << "left:" << leftNode->getchar() << endl;
        popd(finalstack);
        
        // Create the operator node and assign its children
        dNode* doubnode = new dNode(tempchar);
        doubnode->setLeft(leftNode);
        doubnode->setRight(rightNode);
        
        pushd(doubnode, finalstack);
	
        endque = endque->getNext();
      }
   }

    
    treehead = peakd(finalstack);

    dNode* tempno = treehead;

    tempno->setLeft(NULL);
    
    infix(treehead);
    cout << "infix works" << endl;
    destroy(endque);
destroy(midstack);
 destroyd(finalstack);
		     
  return 0;
}

void infix(dNode* root){
  if(root->getLeft() != NULL){
    cout << "going left" <<  endl;
    infix(root->getLeft());
  }
  cout << root->getchar();
  if(root->getRight() != NULL){
    cout << "going right" << endl;
    infix(root->getRight());
   }
}

void pushd(dNode*& nchar, dNode*& stastart){
nchar->setLeft(stastart);
stastart = nchar;
}


dNode* peakd(dNode* stastart){
  if(stastart == nullptr){
    return nullptr ;
  }
  return stastart;
}


void popd(dNode*& stastart){
    if(stastart == nullptr) return;
    stastart = stastart->getLeft();  // Do not delete the node.
}


void destroyd(dNode *& stastart){
  while (stastart != NULL){
    dNode* tempnode = stastart;
    stastart = stastart->getLeft();
    delete tempnode;
}
}


void push(char nchar, Node*& stastart){
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
}

void destroy(Node *& stastart){
  while (stastart != NULL){
    Node* tempnode = stastart;
    stastart = stastart->getNext();
    delete tempnode;
}
}


void enqueue(char nchar, Node*& questart){
  if(questart == nullptr){
    Node* newnode = new Node(nchar);
    questart = newnode;
    return;
  }
  Node* tempnode = questart; 
  while(tempnode->getNext() != NULL){
    tempnode = tempnode->getNext();
  }
  Node* newnode = new Node(nchar);
  tempnode->setNext(newnode);
}

void dequeue(Node*& questart){
  if(questart == nullptr){
    return;
  }
  Node* tempnode = questart;
  questart = questart->getNext();
  delete tempnode;
}
