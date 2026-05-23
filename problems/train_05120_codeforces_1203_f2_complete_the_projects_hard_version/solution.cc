#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int menor(ii a, ii b) { return a.first + a.second < b.first + b.second; }
vector<ii> neg;
vector<ii> pos;
int dp[60010][110];
int main() {
  int n, r;
  int res = 0;
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    ii p;
    cin >> p.first >> p.second;
    if (p.second >= 0)
      pos.push_back(p);
    else {
      p.first = max(-p.second, p.first);
      neg.push_back(p);
    }
  }
  sort(pos.begin(), pos.end());
  for (auto p : pos) {
    if (p.first > r) break;
    r += p.second;
    res++;
  }
  int res2 = 0;
  sort(neg.begin(), neg.end(), menor);
  for (int i = 0; i < neg.size(); i++) {
    for (int x = 0; x <= r; x++) {
      if (i) dp[x][i] = dp[x][i - 1];
      if (x < neg[i].first) continue;
      int q = 1;
      if (i) q = dp[x + neg[i].second][i - 1] + 1;
      dp[x][i] = max(dp[x][i], q);
      res2 = max(res2, dp[x][i]);
    }
  }
  cout << res + res2 << endl;
}
