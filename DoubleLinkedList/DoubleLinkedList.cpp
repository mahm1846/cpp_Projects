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
#include "DoubleLinkedList.h"


using namespace std;


       DoubleLinkedList::DoubleLinkedList( ){
          Head = Tail = NULL;
       }
       //Insert (int, String) pair at the end of the list
       int DoubleLinkedList::insertLast (int num, string value){
           Node *NewNode = new Node();
           NewNode->setNum(num);
           NewNode->setVal(value);

           //Check if the list is empty or not
           if (Tail==NULL){
             Head = NewNode;
             Tail = NewNode;
             NewNode->setNext(NULL);
             NewNode->setPrevious(NULL);
           }
           else{
             Tail->setNext(NewNode);
             NewNode->setPrevious(Tail);
             NewNode->setNext(NULL);
             Tail = NewNode;
           }
           return 0;
       }

       // Insert at the first of the list
       int DoubleLinkedList::insertFirst(int num, string value){
           Node *NewNode = new Node();
           NewNode->setNum(num);
           NewNode->setVal(value);

           // Check if the list is empty or not
           if (Head==NULL){
             Head = NewNode;
             Tail = NewNode;
             NewNode->setNext(NULL);
             NewNode->setPrevious(NULL);
           }
           else{
             NewNode->setPrevious(NULL);
             NewNode->setNext(Head);
             Head->setPrevious(NewNode);
             Head = NewNode;
           }
           return 0;

       }

       //Inset After a given value
       int DoubleLinkedList::insertAfterNum(int num, int NewNam, string NewVal){
           Node *current = Head;
           while(current != NULL && current->getNum() != num){
                current = current->getNext();
           }
           if (current==NULL)
              return -1;

           Node *NewNode = new Node();
           NewNode->setNum(num);
           NewNode->setVal(NewVal);

           NewNode->setNext(current->getNext()) ;
           NewNode->setPrevious(current);
           Node *temp = current->getNext();
           temp->setPrevious(NewNode);
           current->setNext(NewNode);
       }

       //Delete first item of the list
       int DoubleLinkedList::deleteFirst (){
              if (Head==NULL)
                return -1;
              else if (Head==Tail){
                 delete Head;
                 Head = Tail = NULL;
                 return 0;
              }
              Head = Head->getNext() ;
              delete Head->getPrevious();
              Head->setPrevious(NULL);
       }

       //Delete last item of the list
       int DoubleLinkedList::deleteLast (){
              if (Tail==NULL)
                return -1;
              else if (Head==Tail){
                 delete Tail;
                 Head = Tail = NULL;
                 return 0;
              }
              Tail = Tail->getPrevious() ;
              delete Tail->getNext();
              Tail->setNext(NULL);
       }

       //Find a (int) in the list
       Node* DoubleLinkedList::findNum (int num){

           Node *current = Head;
           while(current != NULL && current->getNum() != num){
                current = current->getNext();
           }
           if (current==NULL)
              return NULL;
           cout <<"Found "<< current->getNum()<<" "<<current->getVal()<<endl;
           return current;
       }

       //Delete a (int) value in list
       int DoubleLinkedList::deleteNum (int num){

           Node *current = Head;
           while(current != NULL && current->getNum() != num){
                current = current->getNext();
           }
           if (current==NULL)
              return -1;
           //cout <<"Found "<< current->getNum()<<" "<<current->getVal()<<endl;

           if (current != Head && current != Tail){
               (current->getNext())->setPrevious(current->getPrevious());
               (current->getPrevious())->setNext(current->getNext());
               delete current;
               return 0;
           }
           else if (current==Head)
               return deleteFirst();
           else if (current==Tail)
               return deleteLast();


       }


       //Traverse the list forward direction.
       void DoubleLinkedList::traverse (){
           Node *current = Head;
           while(current != NULL){
              cout << current->getNum()<<" "<<current->getVal()<<endl;
              current = current->getNext();
           }

       }

       //Backward traverse using the Tail
       void DoubleLinkedList::traverseBack (){
           Node *current = Tail;
           while(current != NULL){
              cout << current->getNum()<<" "<<current->getVal()<<endl;
              current = current->getPrevious();
           }

       }

