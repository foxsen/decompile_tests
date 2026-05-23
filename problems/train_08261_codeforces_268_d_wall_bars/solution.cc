#include <bits/stdc++.h>
using namespace std;
const int H = 33;
const int MOD = 1e9 + 9;
int n, h, dp[2][H][H][H][H], vis[H][H][H][H], V;
struct state {
  int a, b, c, d;
};
vector<state> vs, vz;
void inc(int &a, int b) {
  if (a += b, a >= MOD) a -= MOD;
}
void trans(int dp[H][H][H][H], int a, int b, int c, int d, int me) {
  int v[4] = {a, b, c, d};
  sort(v, v + 4);
  for (int i = 0; i < 4; ++i)
    if (v[i] > h + 1) v[i] = h + 1;
  inc(dp[v[0]][v[1]][v[2]][v[3]], me);
  int &z = vis[v[0]][v[1]][v[2]][v[3]];
  if (z != V) {
    z = V;
    vs.push_back((state){v[0], v[1], v[2], v[3]});
  }
}
int main() {
  scanf("%d %d", &n, &h);
  dp[0][0][0][0][0] = 1;
  vs.push_back((state){0, 0, 0, 0});
  int cur = 0, las = cur ^ 1;
  for (int i = 1; i <= n; ++i) {
    swap(cur, las);
    swap(vz, vs);
    vs.clear();
    ++V;
    for (vector<state>::iterator it = vz.begin(); it != vz.end(); ++it) {
      int a = it->a, b = it->b, c = it->c, d = it->d;
      int &me = dp[las][a][b][c][d];
      if (!me) continue;
      trans(dp[cur], a >= h ? h + 1 : 0, b + 1, c + 1, d + 1, me);
      trans(dp[cur], a + 1, b >= h ? h + 1 : 0, c + 1, d + 1, me);
      trans(dp[cur], a + 1, b + 1, c >= h ? h + 1 : 0, d + 1, me);
      trans(dp[cur], a + 1, b + 1, c + 1, d >= h ? h + 1 : 0, me);
      me = 0;
    }
    vz.clear();
  }
  int ans = 0;
  for (int a = 0; a < h; ++a)
    for (int b = a; b <= h + 1; ++b)
      for (int c = b; c <= h + 1; ++c)
        for (int d = c; d <= h + 1; ++d) inc(ans, dp[cur][a][b][c][d]);
  printf("%d\n", ans);
}
