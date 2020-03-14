#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main (){
   int n;
   string s1,s2, strN;
   queue <char> strQ;
   vector <string> resV;
   while(getline(cin,strN) && !strN.empty() ){
       getline(cin,s1);
       n = stoi(strN);
       for (int i=0; i<n; i++){
          for(int j=0; j<s1.length(); j++ ){
             if((s1[j]>='!' && s1[j]<='*')||(s1[j]>='[' && s1[j]<=']')){
                 char tempC = '\\';
                 strQ.push(tempC);
             }
             strQ.push(s1[j]);
          }
          s2="";
          for(int j=0; !strQ.empty(); j++ ){
             s2 += strQ.front();
             strQ.pop();
          }
          s1 = s2;
       }
       resV.push_back(s1);

   }
   for(int i=0;i<resV.size();i++)
      cout<<resV[i]<<endl;

}
