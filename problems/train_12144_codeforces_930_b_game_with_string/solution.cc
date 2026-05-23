#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  double ans = 0.0;
  vector<int> all[26];
  for (int i = 0; i < s.length(); i++) {
    all[s[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; i++) {
    if (all[i].size() == 0) {
      continue;
    }
    double now = 0.0;
    for (int j = 1; j < n; j++) {
      int bo[26];
      for (int a = 0; a < 26; a++) {
        bo[a] = 0;
      }
      double here = 0.0;
      for (int a = 0; a < all[i].size(); a++) {
        int v = (int)(s[(all[i][a] + j) % n] - 'a');
        bo[v]++;
      }
      for (int a = 0; a < 26; a++) {
        if (bo[a] == 1) {
          here += (1.0 / (double)all[i].size());
        }
      }
      now = max(now, here * (double)all[i].size() / (double)n);
    }
    ans += now;
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
