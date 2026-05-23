#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int inf = 100000;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > t(n);
  for (int i = 0; i < n; i++) cin >> t[i].first >> t[i].second;
  n++;
  t.push_back(make_pair(86401, 1));
  int K = n - k;
  vector<int> d(K + 1, inf);
  d[0] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int p = max(i - k, 0);
    int m = inf;
    for (int j = p; j <= K; j++) m = min(m, d[j]);
    if (m <= t[i].first) ans = max(ans, t[i].first - m);
    for (int j = K; j > 0; j--) {
      int u;
      if (d[j - 1] > t[i].first)
        u = d[j - 1] + t[i].second;
      else
        u = t[i].first + t[i].second;
      d[j] = min(d[j], u);
    }
  }
  cout << ans << endl;
}
