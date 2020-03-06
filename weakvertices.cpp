#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

   short n;
   bool *weak, **adj;
   short totalAdj = 0;
   vector<string> output;

   while(1){
     cin>>n;
     if (n == -1) break;
     weak = new bool[n];
     adj = new bool*[n];

     for(int i=0; i< n; i++){
        weak[i] = true;
        adj[i] = new bool[n];
     }
    short x;
    for(int i=0; i<n ; i++)
       for(int j=0; j<n; j++){
          cin>>x;
          if(x==1) adj[i][j] = true;
          else if (x==0) adj[i][j] = false;
       }

    for(int i=0; i<n ; i++)
       for(int j=0; j<n; j++)
           if (adj[i][j]==true && i!=j)
               for (int k=0; k<n; k++)
                   if (j!=k && adj[j][k]==true && adj[k][i]==true){
                        weak[i] = weak[j] = weak[k] = false;
                   }
     string str;
     for(int i=0;i<n;i++)
        if (weak[i]==true){
            str = str + to_string(i);
            if (i != n-1)
                str = str + " ";
        }
     output.push_back(str);
     totalAdj++;
   }

   for(int i=0;i<totalAdj;i++)
       cout<<output[i]<<"\n";
}
