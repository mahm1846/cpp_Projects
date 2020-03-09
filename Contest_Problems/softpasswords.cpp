#include <iostream>
#include <string>

using namespace std;

int main (){
    string s,p;

    cin>>s;
    cin>>p;

    if (s.compare(p)==0){
        cout<<"Yes\n";
        return 0;
    }

    for (int i=0; i<=9; i++){
       if (to_string(i)+p == s || p+to_string(i) == s){
          cout<<"Yes\n";
          return 0;
       }
    }

    for (int i=0; i<p.length(); i++){
        if (isupper(p[i]))
            p[i] = tolower(p[i]);
        else if (islower(p[i]))
            p[i] =toupper(p[i]);
    }

    if (s.compare(p)==0){
        cout<<"Yes\n";
        return 0;
    }


    for (int i=0; i<=9; i++){
       if (to_string(i)+p == s || p+to_string(i) == s){
          cout<<"Yes\n";
          return 0;
       }
    }

    cout<<"No\n";
    return 0;
}
