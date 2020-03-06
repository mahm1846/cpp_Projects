#ifndef NODE_H
#define NODE_H

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
     void setVal (string value);
     void setNum (int number);
     string getVal ();
     int getNum();
     void setNext(Node * next);
     Node* getNext();
     void setPrevious(Node * previous);
     Node* getPrevious();
};
#endif /* HEADERGAURD */
