#include<iostream>
using namespace std;

int main(){
   int n, m;
   char solved [100];
   int  time[100];
   char pChar;
   string status;

   for(int i=0; i<100; i++){
        solved[i] = 'N';
        time[i] = 0;
   }

   while(1){
      cin>>m;
      if (m==-1)
         break;
      cin>>pChar>>status;

      if(solved[pChar-'A'] == 'Y'){
          continue;
      }
      else if(status=="right"){
         solved[pChar-'A'] = 'Y';
         time[pChar-'A'] += m;
      }
      else if (status=="wrong"){
          time[pChar-'A'] +=20;
      }
   }
   int totalTime=0, totalSolved=0;
   for(int i=0; i<100; i++){
       if(solved[i] == 'Y'){
           totalSolved += 1;
           totalTime += time[i];
      }
   }
    cout<<totalSolved<<" "<<totalTime<<"\n";
}
