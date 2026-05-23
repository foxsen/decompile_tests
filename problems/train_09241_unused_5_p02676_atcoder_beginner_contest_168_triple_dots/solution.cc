#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  long k;
  cin >> k;
  cin >> s;
  if (s.size() > k){
    s = s.substr(0,k)+"...";
  }
  cout << s << endl;
}