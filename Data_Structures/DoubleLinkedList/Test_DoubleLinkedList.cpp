/* Testing the DoubleLinkedList class
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include "DoubleLinkedList.h"

using namespace std;


int main(){

  class DoubleLinkedList dll;

  //"Insert value at the end"

  dll.insertLast(1, "one");
  dll.insertLast(2, "two");
  dll.insertLast(3, "three");
  dll.insertLast(4, "four");
  dll.insertLast(5, "five");

  printf("%s","Initial Froward Traverse\n");
  dll.traverse();

  /*"Insert after a value,
   This one not entered as 10 is not present in the list"*/
  dll.insertAfterNum(10, 4.5,"four.five");
  //This one works as 4 is present
  dll.insertAfterNum(4, 4.5,"four.five");

  //Insert First
  dll.insertFirst(0, "Zero");

  printf("%s","Froward Traverse After insertion\n");
  dll.traverse();

  //delete some values
  dll.deleteFirst();
  dll.deleteLast();
  dll.deleteNum(5);

  printf("%s","Backward Traverse after deletions\n");
  dll.traverseBack ();

  return 0;
}
