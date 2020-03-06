/**
Set union with path compression
*/
#include <cstdlib>
#include <iostream>
#include <tgmath.h>
#include <string>
#include <stdio.h>

using namespace std;

class setUnion {
   int componentSize;
   int arraySize;
   int *componentArray;
   int *parent;

   public:

   setUnion(int setSize){
      arraySize = setSize;
      componentSize = setSize;
      componentArray = new int [setSize];
      parent = new int [setSize];

      for (int i=0; i<setSize; i++ ){
          componentArray[0] = 1;
          parent[i] = i;
      }
   }
   char findRoot(char a){
       int x = a - 'a';
       int next = parent[x];
       while(next != parent[next]){
            next = parent[next];
       }
       int root = next;
       next = parent[x];
       while (root != parent[next] ){
           int temp = parent[next];
           parent[next] = root;
           next = temp;
       }
       return char(root+'a');
   }

   int unify(char a,char b){
       cout<<"unify ("<<a<<", "<<b<<")"<<endl;
       char pa = findRoot(a);
       char pb = findRoot(b);

       if (pa==pb)
          return -1;

       if (componentArray[pa-'a']>componentArray[pb-'a']){
             parent[b-'a'] = pa-'a';
             componentArray[pa-'a'] += componentArray[pb-'a'];
       }
       else{
            parent[a-'a'] = pb-'a';
            componentArray[pa-'a'] += componentArray[pb-'a'];
       }
       componentSize--;
       return 0;
  }

  int isConnected(char a, char b){
      if (findRoot(a)==findRoot(b)){
        cout<<a<<", "<<b<<" are connected"<<endl;
        return 0;
      }
      else{
         cout<<a<<", "<<b<<" are Not connected"<<endl;
         return -1;
      }
  }

  void show(){
      cout<<"Array: ";
       for (int i=0;i<arraySize;i++){
           cout<<""<<char(i+'a')<<"->p:"<<char(parent[i]+'a')<<", ";
       }
       cout<<endl;
  }

};

int main(){
   class setUnion su(10);

   su.show();
   su.unify('a','b');
   su.isConnected('a','b');
   su.unify('c','d');
   su.isConnected('c','d');
   su.unify('e','f');
   su.isConnected('e','f');
   su.unify('g','h');
   su.isConnected('g','h');
   su.unify('i','j');
   su.isConnected('i','j');
   su.show();

   su.unify( 'j','g' );
   su.show();
   su.unify( 'h','f' );
   su.show();
   su.unify( 'a','c' );
   su.show();
   su.unify( 'd','e' );
   su.show();
   su.unify( 'g','b' );
   su.show();
   su.unify( 'i','j' );
   su.show();
   return 0;
}

