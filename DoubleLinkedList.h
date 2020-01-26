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

using namespace std;

/* Nodes of the Double link list */
class Node{
   int number;
   string value;
   Node * next;
   Node * previous;

   public:
     void setVal (string value){
       this->value = value;
     }
     void setNum (int number){
       this->number = number;
     }
     string getVal (){
       return value;
     }
     int getNum(){
       return number;
     }
     void setNext(Node * next){
        this->next = next;
     }
     Node* getNext(){
        return next;
     }
     void setPrevious(Node * previous){
        this->previous = previous;
     }
     Node* getPrevious(){
        return previous;
     }
};


//Double Linked list class */
class DoubleLinkedList{

   Node *Head, *Tail;

   public:
       //Constructor
       DoubleLinkedList( ){
          Head = Tail = NULL;
       }
       //Insert (int, String) pair at the end of the list
       int insertLast (int num=0, string value=" "){
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
       int insertFirst(int num=0, string value = " "){
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
       int insertAfterNum(int num, int NewNam=0, string NewVal= " "){
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
       int deleteFirst (){
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
       int deleteLast (){
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
       Node* findNum (int num){

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
       int deleteNum (int num){

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
       void traverse (){
           Node *current = Head;
           while(current != NULL){
              cout << current->getNum()<<" "<<current->getVal()<<endl;
              current = current->getNext();
           }

       }

       //Backward traverse using the Tail
       void traverseBack (){
           Node *current = Tail;
           while(current != NULL){
              cout << current->getNum()<<" "<<current->getVal()<<endl;
              current = current->getPrevious();
           }

       }


};
