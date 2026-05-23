#include <bits/stdc++.h>
using namespace std;
vector<pair<int, vector<int>>> a;
int n;
int m;
int mdp[5000][14];
int tE[12] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
int cost[13][5000][13];
int dp(int tt, int i) {
  if (i == m) return 0;
  if (tE[n - 1] == (tt + 1)) return 0;
  if (mdp[tt][i] != -1) return mdp[tt][i];
  int max_ = 0;
  for (int j = 0; j < tE[n - 1]; j++) {
    if ((j & tt) != 0) continue;
    for (int x = 0; x < n; x++) {
      int sum = 0;
      if (cost[i][j][x] != -1)
        sum = cost[i][j][x];
      else {
        for (int k = 0; k < n; k++)
          if ((j & (1 << k)) != 0) sum += a[i].second[(k + x) % n];
        cost[i][j][x] = sum;
      }
      max_ = max(max_, dp(j | tt, i + 1) + sum);
    }
  }
  return mdp[tt][i] = max_;
}
int main() {
  int TEST;
  cin >> TEST;
  for (int TOOT = 0; TOOT < TEST; TOOT++) {
    memset(mdp, -1, sizeof(mdp));
    memset(cost, -1, sizeof(cost));
    int cin_;
    cin >> n >> m;
    a.assign(m, pair<int, vector<int>>(0, vector<int>(0)));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> cin_;
        a[j].second.push_back(cin_);
        a[j].first = max(a[j].first, cin_);
      }
    sort(a.rbegin(), a.rend());
    m = min(m, n);
    cout << dp(0, 0) << '\n';
  }
  return 0;
}
