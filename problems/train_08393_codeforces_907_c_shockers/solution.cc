#include <bits/stdc++.h>
using namespace std;
void reading(int st) {
  for (int i = 0; i < 3; ++i) {
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> alp(26, 0);
  bitset<26> us = (1 << 27) - 1;
  int ans = 0;
  bool fl = false;
  for (int N = 0; N < n - 1; ++N) {
    string c;
    cin >> c;
    if (c[0] == '.') {
      string w;
      cin >> w;
      for (int i = 0; i < w.length(); ++i) {
        alp[w[i] - 'a']++;
        us[w[i] - 'a'] = 0;
      }
    }
    if (c[0] == '!') {
      string w;
      cin >> w;
      bitset<26> x = 0;
      if (us.count() == 1) ans++;
      for (int i = 0; i < w.length(); ++i) {
        alp[w[i] - 'a']++;
        x[w[i] - 'a'] = 1;
      }
      us &= x;
    }
    if (c[0] == '?') {
      string w;
      cin >> w;
      if (us.count() == 1) ans++;
      us[w[0] - 'a'] = 0;
    }
  }
  cout << ans;
  return 0;
}
