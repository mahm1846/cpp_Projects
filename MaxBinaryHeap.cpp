/**
Implementation of Binary Max Priority Heap using dynamic array
*/
#include <cstdlib>
#include <iostream>
#include <tgmath.h>
#include <string>
#include <stdio.h>

using namespace std;

class MaxBinaryHeap{

     int *Heap;
     int  NumberOfElements;
     int  HeapSize;

public:

     MaxBinaryHeap(int HeapSize){
        Heap = new int (HeapSize+1);
        this->HeapSize = HeapSize;
        NumberOfElements = 1;

        for(int i=0;i<HeapSize;i++)
            Heap[i]=-1;
     }

     ~MaxBinaryHeap(){
        delete Heap;
     }
     int insertHeap(int num);
     int popHeap();
     void showHeap();


};

     int MaxBinaryHeap::insertHeap(int num){
          if (NumberOfElements>HeapSize)
              return -1;

          int child  = NumberOfElements;
          int parent = NumberOfElements/2 ;

          Heap[NumberOfElements] = num;
         //cout<<NumberOfElements<<", P-"<<parent<<",  c-"<<child<<endl;

          while (parent >= 1){
             if (Heap[parent]<Heap[child]){
                int temp     = Heap[parent];
                Heap[parent] = Heap[child];
                Heap[child]  = temp;
                child = parent;
                parent = (parent/2) ;
              }
              else break;
                //cout<<"p: "<<parent<<",  c: "<<child<<endl;
          }
          NumberOfElements++;
          printf("Inserted %3d at Index[%d] \n", num, child);
          return 0;
          //cout<<"---------"<<endl;
      }

      int MaxBinaryHeap::popHeap(){
           int val = Heap[1];
           //cout<<"Heap[NumberOfElements-1]"<<Heap[NumberOfElements-1];
           Heap[1] = Heap[NumberOfElements-1];
           Heap[NumberOfElements-1]=-1;

           int current = 1;
           int leftChild;
           int rightChild;
           int maxIndex ;

           while(1){
              maxIndex = current;
              leftChild  = 2*current;
              rightChild = 2*current+1;

              if (leftChild >=NumberOfElements || rightChild >= NumberOfElements )
                 break;

              if(Heap[current]>=Heap[leftChild] && Heap[current]>=Heap[rightChild])
                  break;

              if (Heap[leftChild]>Heap[current])
                   maxIndex = leftChild;
              if (Heap[rightChild]>Heap[maxIndex])
                   maxIndex = rightChild;

              int temp = Heap[current];
              Heap[current] = Heap[maxIndex];
              Heap[maxIndex] = temp;

              current = maxIndex;
              /*
              for (int i=0;i<HeapSize;i++)
                cout<<Heap[i]<<"  ";
              cout<<endl;
              */
              //cout<<"m: "<<maxIndex<<" v: "<<Heap[maxIndex];
           }
           NumberOfElements--;
           return val;
      }

      void MaxBinaryHeap::showHeap(){

           int l = ceil( log2(NumberOfElements) );

           int  progress=1;
           for (int i=0; i<=l; i++){

                for (int j=0; j<(l-i); j++)
                    cout<<"  ";

                for ( ; progress<pow(2,i+1)&& progress<NumberOfElements ; progress++){
                    cout<<Heap[progress]<<"";
                    for (int k=0; k<(l-i); k++)
                        cout<<" ";
                }
                cout<<endl;
           }
           /*
           for (int i=0;i<HeapSize;i++)
               cout<<Heap[i]<<"  ";
           cout<<endl;
           */
      }


int main (int argc, char **argv){

   MaxBinaryHeap mbh(20);

   mbh.insertHeap(1);
   mbh.insertHeap(21);
   mbh.insertHeap(13);
   mbh.insertHeap(31);
   mbh.insertHeap(45);
   mbh.insertHeap(65);
   mbh.insertHeap(23);
   mbh.insertHeap(13);
   mbh.insertHeap(6);
   mbh.insertHeap(71);
   mbh.insertHeap(8);
   mbh.insertHeap(30);
   mbh.insertHeap(9);
   mbh.insertHeap(10);

   cout<<endl<<"Heap:"<<endl;
   mbh.showHeap();

   cout<<"Pop "<<mbh.popHeap()<<endl;
   cout<<"Pop "<<mbh.popHeap()<<endl;

   cout<<endl<<"Heap:"<<endl;
   mbh.showHeap();


}


