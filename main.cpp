/*
Henry Xu
3/4/25
SHUNTING YARD WITH POSTFIX, PREFIX AND INFIX
Expression tree too.
*/
#include <iostream>
#include <cstring>
#include "node.h"
#include "dnode.h"
#include "enode.h"
using namespace std;

void push(char nchar, Node*& stastart);// init all functions
char peak(Node* stastart);
void pop(Node*& stastart);
void enqueue(char nchar, Node*& questart);
void dequeue(Node*& questart);
void destroy(Node *& stastart);
void pushd(eNode*& nchar, eNode*& stastart);
eNode* peakd(eNode* stastart);
void popd(eNode*& stastart);
void destroyd(eNode *& stastart);
void infix(dNode* root);
void prefix(dNode* root);
void postfix(dNode* root);
void destorytree(dNode* head);

int main(){
  Node* endque = nullptr;//init all varriables
  Node* midstack = nullptr;
  eNode* finalstack2 = NULL;
  dNode* treehead = nullptr;
  char in[50];//ask for input
  cout << endl << "What would you like to input?(It cannot be longer then 50 and no spaces): ";
  cin >> in;
  int x = 0;
  while(in[x] != '\0'){
    char tempchar = in[x];//if character is number then add it to the queue
    if(tempchar == '0' || tempchar == '1' || tempchar == '2' || tempchar == '3' || tempchar == '4' || tempchar == '5' || tempchar == '6' || tempchar == '7' || tempchar == '8' || tempchar == '9'){
      enqueue(tempchar, endque);
      x++;
    }

    else if(tempchar == '+' || tempchar == '-'){//if character is + or - then pop anything lower priority onto the queue
      while(peak(midstack) == '+' || peak(midstack) == '-' || peak(midstack) == '/' || peak(midstack) == '*' || peak(midstack) == '^'){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      push(tempchar, midstack);
      x++;
    }

    else if(tempchar == '*' || tempchar == '/'){//if character is / or * then pop anything lower priority onto the queue
      while(peak(midstack) == '/' || peak(midstack) == '*' || peak(midstack) == '^'){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      push(tempchar, midstack);
      x++;
    }

    else if(tempchar == '^'){//if character is ^ then pop only itself onto the queue
      while(peak(midstack) == '^'){
        enqueue(peak(midstack),endque);
        pop(midstack);
      }
      push(tempchar, midstack);
      x++;
    }

    else if(tempchar == '('){// if the character is ( then look for ) and once found pop everything inbetween
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
    else{//wrong input
      cout << "error" << endl;
      break;
    }
  }
  
  while(midstack != nullptr) {//pushing everything at the end onto the queue also
    enqueue(peak(midstack), endque);
    pop(midstack);
  }
  
  Node* tempstastart = endque;// printing in postfix as a check
    while(tempstastart != NULL){
      cout << tempstastart->getchar();
      tempstastart = tempstastart->getNext();
    }

    while(endque != NULL){//building tree
      char tempchar = endque->getchar();// if char is num then push it onto a new stack
      if(tempchar == '0' || tempchar == '1' || tempchar == '2' || tempchar == '3' || tempchar == '4' || tempchar == '5' || tempchar == '6' || tempchar == '7' || tempchar == '8' || tempchar == '9'){
	      dNode* doubnode = new dNode(tempchar);
        eNode* stacknode = new eNode(doubnode);
	      pushd(stacknode, finalstack2);
	      endque = endque->getNext();
      }
      else{// if the char is not a num then pop 2 things from the stack and make them the left and right child of this char
	      eNode* rightNode = finalstack2;
        popd(finalstack2);
        eNode* leftNode = finalstack2;
        popd(finalstack2);
        
        //create the node and assign the node's childs
        dNode* doubnode = new dNode(tempchar);
        doubnode->setLeft(leftNode->getnode());
        doubnode->setRight(rightNode->getnode());
        
        eNode* stacknode = new eNode(doubnode);

        pushd(stacknode, finalstack2);
	
        endque = endque->getNext();
      }
   }

    
    treehead = finalstack2->getnode();// tree head is the start of the tree
  
    char i2n[50];// ask user for what they want to do
    char postfixn[50] = "postfix";
    char infixn[50] = "infix";
    char prefixn[50] = "prefix";
    cout << endl << "what format?: ";
    cin >> i2n;
    if(strcmp(i2n, postfixn) == 0){
      postfix(treehead);
    }
    else if(strcmp(i2n, prefixn) == 0){
      prefix(treehead);
    }
    else if(strcmp(i2n, infixn) == 0){
      infix(treehead);
    }

    destroy(endque);// destory everything
    destroy(midstack);
    destroyd(finalstack2);
    destorytree(treehead);

  return 0;
}


void destorytree(dNode* head){//function for destorying tree
    if (head == nullptr) return; 
      destorytree(head->getLeft());
      destorytree(head->getRight());
      delete head;
}


void infix(dNode* root){//function for outputing in infix
  if(root->getLeft() != NULL){
    infix(root->getLeft());
  }
  cout << root->getchar();
  if(root->getRight() != NULL){
    infix(root->getRight());
   }
}

void prefix(dNode* root){//function for outputting in prefix
  cout << root->getchar();
  if(root->getLeft() != NULL){
    infix(root->getLeft());
  }
  if(root->getRight() != NULL){
    infix(root->getRight());
   }
}

void postfix(dNode* root){//function for outputting in postfix
  if(root->getLeft() != NULL){
    infix(root->getLeft());
  }
  if(root->getRight() != NULL){
    infix(root->getRight());
   }
 cout << root->getchar();
}

void pushd(eNode*& nchar, eNode*& stastart){//function for pushing the nodes used to build tree
nchar->setNext(stastart);
stastart = nchar;
}


eNode* peakd(eNode* stastart){//function for peaking nodes used to build tree
  if(stastart == NULL){
    return NULL;
  }
  return stastart;
}


void popd(eNode*& stastart){//function for popping nodes used for build tree
  if(stastart == NULL){
    return;
  }
  eNode* tempnode = stastart;
  stastart = stastart->getNext();
}


void destroyd(eNode *& stastart){//function for destorying nodes used for build tree
  while (stastart != NULL){
    eNode* tempnode = stastart;
    stastart = stastart->getNext();
    delete tempnode;
}
}


void push(char nchar, Node*& stastart){//function for pushing nodes used for shunting - stack
Node* newnode = new Node(nchar);
newnode->setNext(stastart);
stastart = newnode;
}


char peak(Node* stastart){//function for peaking nodes used for shutning - stack
  if(stastart == nullptr){
    return '\0' ;
  }
  return stastart->getchar();
}


void pop(Node*& stastart){//function for popping nods used for shunting - stack
  if(stastart == nullptr){
    return;
  }
  Node* tempnode = stastart;
  stastart = stastart->getNext();
  delete tempnode;
}

void destroy(Node *& stastart){//function for destorying nodes used for shunting - stack, queue
  while (stastart != NULL){
    Node* tempnode = stastart;
    stastart = stastart->getNext();
    delete tempnode;
}
}


void enqueue(char nchar, Node*& questart){//function for enqueueing nodes used for shunting - queue
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

void dequeue(Node*& questart){//function for dequeing nodes used for shunting - queue
  if(questart == nullptr){
    return;
  }
  Node* tempnode = questart;
  questart = questart->getNext();
  delete tempnode;
}
