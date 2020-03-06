#include <iostream>
#include <cmath>

using namespace std;

long double calculatePOW(long double x, long double y, long double m){
     long double power=x;
     for ( long double i=1;i<y; ++i)
          power *=x;
          if (power > m){
              return -1;
          }
     //cout<<"\npower: "<<power<<"\n";
     return power;
 }

int main(){
  long double m,n;
  int t;
  long double factorial, power;

  cin>>m>>n>>t;

  //if (m>pow(10,9) || m <1){cout<<"TLE";return 0;}
  //if (n>pow(10,9) || n <1){cout<<"TLE";return 0;}
  //if (t>7 || m <1){cout<<"TLE";return 0;}

  switch(t){
     case 1: factorial = 1.0;
             for (long double i=n;i>0; --i){
               if (factorial > m){
                  cout<<"TLE";
                  return 0;
               }
               factorial *=i;
             }
             //cout<<"\nfactorial: "<<factorial<<"\n";
             factorial <= m ? cout<<"AC" : cout<<"TLE";
             break;

     case 2: power = calculatePOW(2,n,m);
             if (power <= -1){
                 cout<<"TLE";
                 return 0;
             }
             power<= m ? cout<<"AC" : cout<<"TLE";
             break;

     case 3: power = calculatePOW(n,4,m);
             if (power <= -1){
                 cout<<"TLE";
                 return 0;
             }
             power<= m ? cout<<"AC" : cout<<"TLE";
             break;

     case 4: power = calculatePOW(n,3,m);
             if (power <= -1){
                 cout<<"TLE";
                 return 0;
             }
             power<= m ? cout<<"AC" : cout<<"TLE";
             break;

     case 5: power = calculatePOW(n,2,m);
             if (power <= -1){
                 cout<<"TLE";
                 return 0;
             }
             power<= m ? cout<<"AC" : cout<<"TLE";
             break;

     case 6: if (n>=4 && n>= m) {
                cout<<"TLE";
             }
             (n*log2(n))<= m ? cout<<"AC" : cout<<"TLE";
             //cout<<" n*log2(n): "<<n*log2(n);
             break;

     case 7: n<= m ? cout<<"AC" : cout<<"TLE";
             break;

     default: cout<<"TLE";


  }

}
