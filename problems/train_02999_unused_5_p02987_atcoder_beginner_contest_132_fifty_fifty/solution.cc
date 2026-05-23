#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[4];
  for(int i=0;i<4;++i) cin >> s[i];
  sort(s,s+4);
  if(s[0]==s[1]&&s[2]==s[3]&&s[1]!=s[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
}