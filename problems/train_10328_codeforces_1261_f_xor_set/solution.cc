#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, inv2 = (mod + 1) / 2;
int n, m, rt[2], ch[60 * 100 * 8][2], cnt, ans;
bool Real[60 * 100 * 8];
void ins(int &i, long long l, long long r, long long x, long long y) {
  if (!i) i = ++cnt;
  if (x <= l && r <= y) return void(Real[i] = 1);
  long long mid = (l + r) >> 1;
  if (x <= mid) ins(ch[i][0], l, mid, x, y);
  if (y > mid) ins(ch[i][1], mid + 1, r, x, y);
}
vector<pair<int, int> > q[65];
void solve(long long x, int d) {
  for (pair<int, int> now : q[d])
    if (Real[now.first] || Real[now.second])
      return void(ans = (ans + (x % mod + ((1ll << d) % mod - 1) * inv2 % mod) *
                                   ((1ll << d) % mod)) %
                        mod);
  for (int i = 0; i < 2; i++) {
    q[d - 1].clear();
    for (pair<int, int> now : q[d])
      for (int j = 0; j < 2; j++)
        if (ch[now.first][j] && ch[now.second][i ^ j])
          q[d - 1].push_back(
              pair<int, int>(ch[now.first][j], ch[now.second][i ^ j]));
    if (q[d - 1].size()) solve(x | (i ? 1ll << (d - 1) : 0), d - 1);
  }
}
int main() {
  scanf("%d", &n);
  long long x, y;
  while (n--) scanf("%lld%lld", &x, &y), ins(rt[0], 0, (1ll << 60) - 1, x, y);
  scanf("%d", &m);
  while (m--) scanf("%lld%lld", &x, &y), ins(rt[1], 0, (1ll << 60) - 1, x, y);
  q[60].push_back(pair<int, int>(rt[0], rt[1]));
  solve(0, 60);
  printf("%d\n", ans);
}
