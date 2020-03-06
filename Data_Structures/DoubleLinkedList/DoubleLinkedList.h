#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

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


//Double Linked list class */
class DoubleLinkedList{

   class Node *Head, *Tail;

   public:
       //Constructor
       DoubleLinkedList( );
       //Insert (int, String) pair at the end of the list
       int insertLast (int num=0, string value=" ");
       // Insert at the first of the list
       int insertFirst(int num=0, string value=" ");
       //Inset After a given value
       int insertAfterNum(int num, int NewNam=0, string NewVal=" ");
       //Delete first item of the list
       int deleteFirst ();
       //Delete last item of the list
       int deleteLast ();
       //Find a (int) in the list
       Node* findNum (int num);
       //Delete a (int) value in list
       int deleteNum (int num);
       //Traverse the list forward direction.
       void traverse ();
       //Backward traverse using the Tail
       void traverseBack ();

};
#endif /* HEADERGAURD */
