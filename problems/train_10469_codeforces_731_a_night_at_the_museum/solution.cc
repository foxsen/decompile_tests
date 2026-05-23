#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int pev = 'a';
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int temp = abs(s[i] - pev);
    temp = min(temp, 26 - temp);
    ans += temp;
    pev = s[i];
  }
  cout << ans;
}
