#include <bits/stdc++.h>
using namespace std;
const int N = 1000000, M = 20;
int n, m;
struct side {
  int y, next;
} e[N * 2 + 9];
int lin[N + 9], cs;
void Ins(int x, int y) {
  e[++cs].y = y;
  e[cs].next = lin[x];
  lin[x] = cs;
}
int in[N + 9], out[N + 9];
void into() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Ins(x, y);
    ++in[y];
    ++out[x];
  }
}
int dp[N + 9], vis[N + 9], c;
int Dfs_dp(int k) {
  if (vis[k]) return dp[k];
  vis[k] = 1;
  if (!out[k]) dp[k] |= 1 << c++;
  for (int i = lin[k]; i; i = e[i].next) dp[k] |= Dfs_dp(e[i].y);
  return dp[k];
}
void Get_dp() {
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) Dfs_dp(i);
}
int to[(1 << M) + 9], cnt[(1 << M) + 9], ans;
void Get_to() {
  c = 0;
  for (int i = 1; i <= n; ++i)
    if (!in[i]) to[1 << c++] = dp[i];
  ans = 1;
  for (int s = 0; s < 1 << c; ++s) cnt[s] = cnt[s >> 1] + (s & 1);
  for (int s = 1; s < 1 << c; ++s) {
    to[s] = to[s & -s] | to[s ^ s & -s];
    cnt[s] = cnt[s >> 1] + (s & 1);
    if (cnt[to[s]] < cnt[s]) ans = 0;
    if (s ^ (1 << c) - 1 && cnt[to[s]] == cnt[s]) ans = 0;
  }
}
void work() {
  Get_dp();
  Get_to();
}
void outo() { puts(ans ? "YES" : "NO"); }
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
