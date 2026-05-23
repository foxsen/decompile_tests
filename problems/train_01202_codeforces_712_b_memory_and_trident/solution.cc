#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  if (n & 1) {
    cout << -1;
    return 0;
  }
  int a = 0, b = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'U') a++;
    if (s[i] == 'D') a--;
    if (s[i] == 'L') b++;
    if (s[i] == 'R') b--;
  }
  a = abs(a);
  b = abs(b);
  int min_val = min(a, b);
  int max_val = max(a, b);
  int ans = (max_val - min_val) / 2 + min_val;
  cout << ans;
}
