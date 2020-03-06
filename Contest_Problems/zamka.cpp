#include<iostream>
using namespace std;

int main(){
   int l,d,x,n=-1,m=-1;

   cin>>l;
   cin>>d;
   cin>>x;

   for(int i=d;i>=l;i--){
        string str = to_string(i);
        int len = str.length();
        int total=0;
        for(int j=0;j<len;j++){
            total +=(str[j]-'0');
        }
        if(total==x){
            m=i;
            break;
        }
   }

   for(int i=l;i<=d;i++){
        string str = to_string(i);
        int len = str.length();
        int total=0;
        for(int j=0;j<len;j++){
            total +=(str[j]-'0');
        }
        if(total==x){
            n=i;
            break;
        }
   }

   cout<<n<<"\n";
   cout<<m<<"\n";

}
