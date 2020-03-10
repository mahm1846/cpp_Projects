#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
 using namespace std;

int main(){
   int n ;
   double p, k, t, original, rate, lapse;

   cin>>n>>p>>k;

   rate = 100;
   original = 0;
   lapse = 0;
   for (int i=0;i<n; i++){
       cin>>t;
       original += (t-lapse ) * (rate/100);
       lapse = t;
       rate += p;
   }
   original += (k-lapse ) * (rate/100);
   cout<<setprecision(10)<<original<<"\n";

}
