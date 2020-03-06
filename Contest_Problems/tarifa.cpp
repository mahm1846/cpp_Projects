#include<iostream>
using namespace std;

int main(){
   int x,n,p;

   cin>>x;
   cin>>n;

   int total = x*(n+1);

   while(n-->0){
      cin>>p;
      total -=p;
   }
   cout<<total;

}
