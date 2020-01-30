/**
Find First duplicate of an array size N;
Numbers are between 1 and N;

Examples
5  2  7  7  2  5  8  3  9  9
 First Duplicate: 7

10  4  3  1  8  3  2  4  1  10
 First Duplicate: 3

9  5  6  9  10  9  8  9  7  9
 First Duplicate: 9

 7  8  3  1  2  1  1  3  1  10
 First Duplicate: 1

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

class firstDuplicate{
    int ArraySize, *NumArray, *PosArray;

    public:
    firstDuplicate(int numSize){
         this->ArraySize = numSize;
         NumArray = new int [numSize];
         PosArray = new int [numSize];

         for(int i=0;i<ArraySize;i++)
            NumArray[i] = PosArray[i] = 0;
    }

    void generateNum(){
         srand (time(NULL));
         for(int i=0; i<ArraySize; i++){
               NumArray[i] = (rand() % ArraySize)+1;
         }
    }
    void showArray(){
         for (int i=0;i<ArraySize; i++)
            cout<<NumArray[i]<<"  ";
    }
    int findFirstDuplicate(){
        int firstDup = -1;

        for(int i=0; i<ArraySize; i++)
            if(NumArray[i]>ArraySize || NumArray[i]< 1){
                cout<<"Invalid Array";
                return -1;
            }

        for(int i=0; i<ArraySize; i++){
            if(PosArray[ NumArray[i]-1 ] == 0){
                PosArray[ NumArray[i]-1 ] = 1;
            }
            else{
                firstDup =  NumArray[i];
                break;
            }
        }
        return firstDup;
    }
};

int main(){
   class firstDuplicate fp(10);
   fp.generateNum();
   fp.showArray();
   cout<<"\n First Duplicate: "<<fp.findFirstDuplicate();
}
