#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string, int> a;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    a[s]++;
  }
  int mx = 0;
  for(auto p : a){
    mx = max(mx, p.second);
  }
  for(auto p : a){
    if(p.second != mx){
      continue;
    }
    cout << p.first << endl;
  }
}
