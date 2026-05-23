#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int n, lim;
long long total;
int t[nax];
void read() {
  scanf("%d%lld%d", &n, &total, &lim);
  set<int> s;
  for (int i = (0); i <= ((n)-1); ++i) {
    scanf("%d", &t[i]);
    s.insert(t[i]);
  }
  map<int, int> m;
  int i = 0;
  for (int a : s) m[a] = i++;
  for (int i = (0); i <= ((n)-1); ++i) t[i] = m[t[i]];
}
vector<vector<int> > dp;
int pre[nax];
int s[nax], s2[nax];
int main() {
  read();
  vector<int> single = vector<int>(n, 0);
  dp = vector<vector<int> >(lim + 1, single);
  dp[0][0] = 1;
  for (int row = (1); row <= ((lim)); ++row) {
    for (int i = (0); i <= ((n)-1); ++i) {
      pre[i] = dp[row - 1][i];
      if (i) add(pre[i], pre[i - 1]);
    }
    for (int i = (0); i <= ((n)-1); ++i) {
      add(dp[row][t[i]], pre[t[i]]);
      add(s[row], pre[t[i]]);
    }
  }
  for (int row = (1); row <= ((lim)); ++row) {
    for (int i = (0); i <= ((n)-1); ++i) {
      pre[i] = dp[row - 1][i];
      if (i) add(pre[i], pre[i - 1]);
    }
    int pom = total % n;
    for (int i = (0); i <= ((pom)-1); ++i) add(s2[row], pre[t[i]]);
  }
  int res = 0;
  long long full = total / n;
  for (int row = (1); row <= ((lim)); ++row) {
    long long x = (row <= full + 1);
    add(res, x * s2[row] % mod);
    x = (full - row + 1) % mod;
    if (x < 0) x = 0;
    add(res, x * s[row] % mod);
  }
  printf("%d\n", res);
  return 0;
}
