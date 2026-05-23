#include <bits/stdc++.h>
using namespace std;
int main() {
  string o,e; cin>>o>>e;
  int i=0;
  char c;
  for(int i=0; i<o.length(); i++) {
    if(e.length()>i) cout<<o[i]<<e[i];
    else cout<<o[i];
  }
}