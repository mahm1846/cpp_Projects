#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

vector <int> ResStore;

int main(){

   string line;

   while (getline(cin, line) && !line.empty()) {

      vector<int> words;
      stringstream ss(line);
      string token;
      while (getline(ss, token, ' ')) {
         words.push_back(stoi(token));
      }

      for (int i=0; i<words.size(); i++ ){
          int sum = 0;
          for(int j=0; j< words.size(); j++){
              if (i!=j) sum += words[j];
          }
          if (sum==words[i]){
               ResStore.push_back(words[i]);
               break;
          }
       }
   }
   for(int i=0; i<ResStore.size(); i++){
       cout<<ResStore[i]<<"\n";
    }
}
