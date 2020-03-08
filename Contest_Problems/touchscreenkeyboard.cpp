#include<iostream>
#include<cstring>
#include <queue>
#include <vector>
using namespace std;

string kb []= {"qwertyuiop",
               "asdfghjkl ",
               "zxcvbnm   "};

int distanceC(char a, char b){
     int i1,j1,i2,j2;
     i1 = j1 = i2 = j2 = -1;
     for (int i=0; i<3; i++)
        for(int j=0; j<kb[i].length(); j++){
            if(a==kb[i][j] && kb[i][j] != ' ' ){
                i1=i; j1=j;
                break;
            }
        }

     for (int i=0; i<3; i++)
        for(int j=0; j<kb[i].length(); j++){
            if(b==kb[i][j] && kb[i][j] != ' ' ){
                i2=i; j2=j;
                break;
            }
        }
     if(i1!=-1&& i2!=-1)
         return abs(i1-i2) + abs(j1-j2);
     else
         return -1;
}


int main(){

   int totalSets;
   string typedW;
   int l;
   string listedW;
   int wordDistance;

   typedef pair<int, string> pi;
   priority_queue<pi, vector<pi>, greater<pi> > pq;

   vector< pair <string,int> > finalList;

   cin>>totalSets;
   for(int k=0; k<totalSets; k++){
       cin>>typedW>>l;
       for(int i=0; i<l; i++){
           cin>>listedW;
           wordDistance = 0;

           for(int i=0; i<typedW.length(); i++)
                wordDistance += distanceC(typedW[i],listedW[i]);

           pq.push(make_pair(wordDistance, listedW));
       }

       for(int i=0; i<l; i++){
            pair<int, string> top = pq.top();
            //cout << top.second << " " << top.first<<"\n";
            pq.pop();
            finalList.push_back( make_pair(top.second,top.first) );
       }
   }

   for(int i=0; i<finalList.size(); i++)
       cout << finalList[i].first << " " << finalList[i].second << endl;

}
