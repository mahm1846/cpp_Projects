/**
Hash Table with Separate Chaining
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
#include <list>
#include <iterator>
#include <iomanip>

using namespace std;

class FenwickTree{

   long *Tree, *values;
   int   TreeSize;

   public:

   FenwickTree(long values[], int arraySize){
       (*this).TreeSize = arraySize;
       (*this).values = values;
       Tree = new long[TreeSize+1];
       Tree[0] = 0;
       for(int i=0;i<arraySize;i++)
          Tree[i+1] = values[i];

       for (int i=1; i<=TreeSize; i++){
          int j = i + (i&-i);
          if (j<=TreeSize)
             Tree[j] = Tree[j] + Tree[i];
       }
    }

    long prefixsum(int i){
       long sum = 0;
       while (i!=0){
          sum = sum + Tree[i];
          i = i - (i & -i);
       }
       return sum;
    }

     long intervalSum(int i, int j){
         if (j<i){
            cout <<" j must be >= i";
            return -1;
         }
         return prefixsum(j) - prefixsum(i-1);
     }

     void addVal (int i, long val){
         while(i<TreeSize){
             Tree[i] = Tree[i] + val;
             i = i + (i & -i);
         }
     }

     void showVals(){
         cout<<"\nVals:      ";
         for(int i=0; i<TreeSize; i++)
            cout<<setw(3)<<*(values+i)<<"  ";

         cout<<"\nTree: ";
         for(int i=0; i<=TreeSize; i++)
            cout<<setw(3)<<*(Tree+i)<<"  ";
     }

};

int main(){
    long values[] = {5, -3, 6, 1, 0, -4, 11, 6, 2, 7};
    FenwickTree fwTree(values, 10);
    fwTree.showVals();
    cout<<"\nPrefixsum: ";
    for (int i=1;i<=10;i++)
        cout<<setw(3)<<fwTree.prefixsum(i)<<"  ";

}
