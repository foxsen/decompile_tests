#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int e, s;
vector<int> v[3];
long long dp[3][200105];
long long cal(int id, int f) {
  int pos = lower_bound(v[id].begin(), v[id].end(), f) - v[id].begin();
  return dp[id][pos] + max(v[id][pos] - f - s, 0);
}
void fmain() {
  scanf("%d%d%d%d", &e, &s, &n, &m);
  for (int i = 0, t, x; i < n; i++) {
    scanf("%d%d", &t, &x);
    if (x >= e) continue;
    for (int(j) = 0; (j) < (int)(t); (j)++) v[j].push_back(x);
  }
  for (int(j) = 0; (j) < (int)(3); (j)++) {
    v[j].push_back(e);
    sort(v[j].begin(), v[j].end());
    for (int i = v[j].size() - 2; i >= 0; i--) {
      dp[j][i] = dp[j][i + 1] + max(v[j][i + 1] - v[j][i] - s, 0);
    }
  }
  for (int i = 0, f; i < m; i++) {
    scanf("%d", &f);
    if (cal(0, f) != 0)
      puts("-1 -1");
    else
      printf("%lld %lld\n", cal(1, f), cal(2, f) - cal(1, f));
  }
}
int main() {
  fmain();
  return 0;
}
