#include <iostream>
#include <string>
#include <vector>
#include "limits.h"
#include <climits>

using namespace std;

long long globalLen , globalMin, x ;
string num;

void HeapPermute(int len){

   if (len == 1){
      //for(int i=0; i<globalLen; i++ )
      //  cout<<num[i];
      //cout<<"\n";
      long t = stol (num);
      if (t> x && t < globalMin)
        globalMin =  t;
      return;
   }

   for(int i=0;i<len;i++){
        HeapPermute(len-1);
        if (len%2==1)
            swap(num[0],num[len-1]);
        else
            swap(num[i],num[len-1]);
   }
}

int main(){

   cin>>num;
   //num="156";
   x = stol(num);

   globalLen = num.length();
   globalMin = LONG_MAX;
   HeapPermute(globalLen);

   if (globalMin == LONG_MAX)
      cout<<"0\n";
   else
      cout<<globalMin<<"\n";


}
