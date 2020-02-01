/**
Binary Search Tree
*/
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

template <class T>
class Node{
    public:
    T data;
    Node *leftChild;
    Node *rightChild;


    Node(){
       this->data = NULL;
       leftChild  = NULL;
       rightChild = NULL;
    }
    Node(T data);
};
  template <class T>
  Node<T>::Node(T data){
       this->data = data;
       leftChild  = NULL;
       rightChild = NULL;
   }



template <class T>
class BinarySearchTree{

      public:
      int totalNodes;
      class Node<T> *root;

      BinarySearchTree(){
          root = NULL;
          totalNodes = 0;
      }
      Node<T>* findVal(T data);
      int insertVal(T data);
      Node<T>* deleteVal(T data);
      void inOrder(Node<T> *root);
      void preOrder(Node<T> *root);
      void postOrder(Node<T> *root);
};

template <class T>
Node<T>* BinarySearchTree<T>::findVal(T data){
     if (root==NULL)
        return NULL;
     Node<T> *current = root;

     while (1){
        if (data > current->data && current->rightChild != NULL)
            current = current->rightChild;
        else if (data < current->data && current->leftChild != NULL)
            current = current->leftChild;
        else if (data == current->data)
            return  current;
        else
            return NULL;
    }
}

template <class T>
int BinarySearchTree<T>::insertVal(T data){

     class Node<T> *newNode;

     cout<<"\nInsert "<<data;
     if (root == NULL){
        newNode = new Node<T>(data);
        root = newNode;
        return 0;
     }
     Node<T> *current = root;
     while (current != NULL){
        if (data < current->data && current->leftChild != NULL)
            current = current->leftChild;
        else if (data > current->data && current->rightChild != NULL)
            current = current->rightChild;
        else if (data == current->data)
            return -1;
        else if (data < current->data ) {
            newNode = new Node<T>(data);
            current->leftChild = newNode;
            return 0;
        }
        else if (data > current->data){
            newNode = new Node<T>(data);
            current->rightChild = newNode;
            return 0;
        }
     }
     return -1;
}

template <class T>
Node<T>* BinarySearchTree<T>::deleteVal(T data){

      if (root==NULL)
        return NULL;
      Node<T> *current = root;

      if (current == NULL)
         return NULL;
      Node<T> *previous = root;

      while (current != NULL){
        if (current->data < data){
            previous = current;
            current = current->rightChild;
        }
        else if(current->data > data ){
            previous = current;
            current  = current->leftChild;
        }
        else if (current->data==data)
            break;
        }
       //cout<<"\ncurrent: "<<current->data;
       //cout<<"\nprevious:"<<previous->data;

       if (current->leftChild==NULL && current->rightChild==NULL){
          current->data > data ? previous->leftChild = NULL : previous->rightChild = NULL;
          if (current==root)
            root=NULL;
          delete current;
       }
       else if (current->leftChild==NULL && current->rightChild != NULL ){
         (current==previous->leftChild) ? previous->leftChild = current->rightChild : previous->rightChild = current->rightChild;
         delete current;
       }
       else if (current->leftChild!=NULL && current->rightChild==NULL){
         (current==previous->rightChild) ? previous->rightChild = current->leftChild : previous->leftChild = current->leftChild;
         delete current;
       }
       else{
          Node<T> *temp = current->rightChild;
          Node<T> *tempPrev = current;
          while (temp->leftChild != NULL){
              tempPrev = temp;
              temp = temp->leftChild;
          }

          //cout<<"\n Right subTree Smallest value "<<temp->data<<endl;
          current->data = temp->data;

          if(tempPrev==current)
             tempPrev->rightChild=NULL;
          else
              tempPrev->leftChild = NULL;
          delete temp;
       }
}


template <class T>
void BinarySearchTree<T>::inOrder(Node<T> *root){
      if(root==NULL)
        return;
      inOrder(root->leftChild);
      cout<<root->data<<"  ";
      inOrder(root->rightChild);
}

template <class T>
void BinarySearchTree<T>::preOrder(Node<T> *root){
      if(root==NULL)
        return;
      cout<<root->data<<"  ";
      preOrder(root->leftChild);
      preOrder(root->rightChild);
}

template <class T>
void BinarySearchTree<T>::postOrder(Node<T> *root){
      if(root==NULL)
        return;
      postOrder(root->leftChild);
      postOrder(root->rightChild);
      cout<<root->data<<"  ";
}



int main(){
    class BinarySearchTree<int> bst;

    bst.insertVal(7);
    bst.insertVal(20);
    bst.insertVal(5);
    bst.insertVal(15);
    bst.insertVal(10);
    bst.insertVal(4);
    bst.insertVal(4);
    bst.insertVal(33);
    bst.insertVal(2);
    bst.insertVal(25);
    bst.insertVal(6);

    cout<<"\n Pre order traverse: "; bst.preOrder(bst.root);
    cout<<"\n In order traverse : "; bst.inOrder(bst.root);
    cout<<"\n Post order traverse: "; bst.postOrder(bst.root);

    printf("\n Searching value 6 : %s",(bst.findVal(6)) != NULL ? "Found":"NOT Found");
    printf("\n Searching value 50: %s",(bst.findVal(50)) != NULL ? "Found":"NOT Found");

    cout<<"\nDelete "<<7;
    bst.deleteVal(7);

    cout<<"\n In order traverse: "; bst.inOrder(bst.root);
    return 0;
}
