#include <iostream>
#include <sstream>

using namespace std;
int main(){

   int a,b;
   int x,y;
   string line;

   getline(cin, line);
   stringstream ss (line);
   string part;
   getline(ss, part, '/');
   a = stol(part);
   getline(ss, part, '/');
   b = stol(part);

   x= (a - 32*b)*5;
   y= (b - 0)*9;
   if(x==0) y=1;

   for(int i=y;i>=1; i--){
       if (x%i==0 && y%i==0){
            x/=i; y/=i;
       }
   }
   cout<<x<<"/"<<y<<"\n";
}
