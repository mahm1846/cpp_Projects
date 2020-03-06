#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include "Node.h"

using namespace std;

/* Nodes of the Double link list */
void Node::setVal (string value){
       this->value = value;
     }

void Node::setNum (int number){
       this->number = number;
     }
string Node::getVal (){
       return value;
     }
int Node::getNum(){
       return number;
     }
void Node::setNext(class Node *next){
        this->next = next;
     }
Node* Node::getNext(){
        return next;
     }
void Node::setPrevious(class Node *previous){
        this->previous = previous;
     }
Node* Node::getPrevious(){
        return previous;
     }

