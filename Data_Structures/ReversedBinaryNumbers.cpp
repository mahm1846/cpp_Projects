#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main(){

  long original=0, reverseNumber=0;

  cin>>original;
  string rStr="";
  while(original!=0){
    rStr=(original % 2 == 0? "0":"1")+rStr;
    original = original / 2;
  }
  //cout<<rStr<<" ";
  for (int i = 0; i < rStr.size(); i++) {
		reverseNumber = reverseNumber + (rStr[i]=='1'? pow(2,i): 0);
	}
cout<<reverseNumber;
}
