# include <iostream>
# include <cmath>

using namespace std;

int main (){
    long c, k, ten;
    double frac, frac2, frac3;

    cin>>c>>k;
    ten = 1;
    for (int i=0; i<k; i++)
        ten *=10;

     frac = (double) c / (double) ten;
     frac2 =  floor(frac);
     frac3 =  ceil (frac);

     //cout<<frac2<<"  "<<frac3<<endl;
     //cout<<( frac2* (double) ten)<<"  "<<(frac3 * (double) ten )<<endl;
     if (c - frac2* (double) ten < frac3 * (double) ten - c )
           cout<<(long) ( frac2* (double) ten);
     else
           cout<<(long) ( frac3* (double) ten );
}
