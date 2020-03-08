#include <iostream>

using namespace std;

int main(){

  int timeleft = 210;
  char answer;
  int k, n, t;

  cin>>k;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>t>>answer;
    timeleft -= t;
    if (answer=='T' && timeleft>0){
        if (k<8) k++;
        else k=1;
    }
    else if (answer=='F' || answer == 'P')
        continue;
  }
  cout<<k<<"\n";
}
