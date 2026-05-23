#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  int sz = s.size();
  for(int i = 0; i<sz;++i){
    if(s.substr(i)==t){
      cout << "Yes" << endl;
      return 0;
    }
    s += s[i];
  }
  cout << "No" << endl;
}

