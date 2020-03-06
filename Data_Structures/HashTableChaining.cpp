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


class HashNode {
    public:
      list <int> keys;
      list <string> values;

      HashNode(){
      }

};

class HashTableChaining{

    public:
      vector <HashNode> *HashTable;
      int    tableSize ;

      HashTableChaining(int tableSize){
           (*this).tableSize = tableSize;
           HashTable = new vector <HashNode> (tableSize) ;
      }

      int insertVal (int key, string val){
           int pos = key % tableSize;
           (*HashTable)[pos].keys.push_back(key);
           (*HashTable)[pos].values.push_back(val);
       }

      void showTable(){
          list<int>:: iterator it1 ;
          list<string>:: iterator it2;
          cout<<"\n====== Hash Table ============"<<endl;
          for (int i=0;i<tableSize;i++){

              cout<<"Hash:"<<i<<"\n";
              for( it1=(*HashTable)[i].keys.begin(); it1!=(*HashTable)[i].keys.end();  it1++){
                    cout<<setw(5)<<*it1<<" -> ";
              }
              cout<<"\n";
              for( it2=(*HashTable)[i].values.begin(); it2!=(*HashTable)[i].values.end() ; it2++){
                   cout<<setw(5)<<(string)(*it2)<<" -> ";
              }
            cout<<endl<<"==========================="<<endl;
          }

      }

      int deleteKey (int key){
          int pos = key % tableSize;
          list<int>:: iterator it1 ;
          list<string>:: iterator it2;

          int keyPos = -1;
          int i = 0;
          it1=(*HashTable)[pos].keys.begin();
          it2=(*HashTable)[pos].values.begin();
          for( ; it1!=(*HashTable)[pos].keys.end();  it1++, i++){
                   if (*it1 == key){
                          cout <<"removing key :"<< *it1<<",  ";
                          it1 = (*HashTable)[pos].keys.erase(it1);
                          keyPos = i;
                          break;
                    }
          }

          int j=0;
          for( ; it2!=(*HashTable)[pos].values.end(), j<=keyPos ; it2++, j++){
                   cout <<"removing value :"<< *it2<<endl;
                   it2 = (*HashTable)[pos].values.erase(it2);
                   return  0;
          }
          cout <<" Key: "<<key<<", not found "<<endl;
          return -1;
      }

      int deleteKey (int key, string val){
          int pos = key % tableSize;
          list<int>:: iterator it1 ;
          list<string>:: iterator it2;

          int i = 0;
          it1=(*HashTable)[pos].keys.begin();
          it2=(*HashTable)[pos].values.begin();
          for( ; it1!=(*HashTable)[pos].keys.end() && it2!=(*HashTable)[pos].values.end() ;  it1++, it2++, i++){
                   if (*it1 == key && *it2 == val){
                          cout <<"removing key :"<< *it1<<" & "<<"removing value :"<< *it2<<endl;
                          it1 = (*HashTable)[pos].keys.erase(it1);
                          it2 = (*HashTable)[pos].values.erase(it2);
                          return i;
                          break;
                    }
          }
          cout <<" Key: "<<key<<" && val:"<<val<<" not found "<<endl;
          return -1;
      }

    void reSizeHash(int newTableSize){
          vector <HashNode> *newHashTable;
          newHashTable = new vector <HashNode> (newTableSize) ;

          list<int>:: iterator it1 ;
          list<string>:: iterator it2;
          int pos;
          for (int i=0;i<tableSize;i++){
              it1=(*HashTable)[i].keys.begin();
              it2=(*HashTable)[i].values.begin();
              for( ; it1!=(*HashTable)[i].keys.end(), it2!=(*HashTable)[i].values.end();  it1++, it2++){
                   pos = *it1 % newTableSize;
                   (*newHashTable)[pos].keys.push_back(*it1);
                   (*newHashTable)[pos].values.push_back(*it2);
               }
              (*HashTable)[i].keys.clear();
              (*HashTable)[i].values.clear();
           }
           delete HashTable;
           (*this).HashTable = newHashTable;
           (*this).tableSize = newTableSize;
    }

};

int main(){

  HashTableChaining hc(6);

  hc.insertVal(21, "will");
  hc.insertVal(25, "Rai");
  hc.insertVal(61, "Rick");
  hc.insertVal(18, "Leah");
  hc.insertVal(34, "Lara");
  hc.insertVal(56, "Ryan");
  hc.insertVal(21, "Finn");
  hc.insertVal(11, "Bob");
  hc.insertVal(10, "Mark");
  hc.showTable();

  hc.deleteKey(21, "Finn");
  hc.showTable();
  cout<<"\nRehashing to size 3 ";
  hc.reSizeHash(3);
  hc.showTable();
  return 0;
}

