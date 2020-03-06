#include<iostream>
#include<string>
using namespace std;

int main(){
   short index=1, len = -1 ;

   string moves;
   cin>>moves;
   len = moves.length();
   for(int i=0; i<len;i++){
      if (moves[i]=='A'){
           if(index==1)
               index = 2;
           else if (index==2)
               index = 1;
       } else if (moves[i] == 'B'){
            if(index==2)
                index = 3;
            else if (index==3)
                index = 2;
        } else if (moves[i] == 'C'){
            if (index == 1)
                index = 3;
            else if(index == 3)
                index = 1;
        }
   }
   cout<<index<<"\n";
}
