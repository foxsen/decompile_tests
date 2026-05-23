#include <bits/stdc++.h>
using namespace std;
const int M = 777777777;
struct segment {
  int l, r;
  inline bool operator<(const segment &s) const { return l < s.l; }
};
int n;
int w[4][4];
int dp[4][77790][4] = {0};
int dp_full;
int dp_r[4][77790] = {0}, dp_l[77790][4] = {0};
int a[77777] = {0};
const int SZ = 131072;
int P[SZ + SZ];
void modify(int x, int v) {
  P[x += SZ] = v;
  while (x >>= 1) P[x] = (long long)P[x + x] * P[x + x + 1] % M;
}
int fuck(const segment &s) {
  if (s.l == 1 && s.r == n + 1) return dp_full;
  if (s.l == 1) {
    assert(a[s.r]);
    return dp_l[s.r - s.l + 1][a[s.r]];
  }
  if (s.r == n + 1) {
    assert(a[s.l - 1]);
    return dp_r[a[s.l - 1]][s.r - s.l + 1];
  }
  assert(a[s.l - 1]);
  assert(a[s.r]);
  return dp[a[s.l - 1]][s.r - s.l + 2][a[s.r]];
}
void check(int x) {
  if (x > n) return;
  if (!a[x])
    return;
  else if (x == 1 || !a[x - 1])
    modify(x, 1);
  else
    modify(x, w[a[x - 1]][a[x]]);
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) scanf("%d", w[i] + j);
  dp[1][1][1] = dp[2][1][2] = dp[3][1][3] = 1;
  for (int k = 1; k <= 3; k++)
    for (int i = 2; i <= n + 2; i++)
      for (int j = 1; j <= 3; j++)
        for (int jj = 1; jj <= 3; jj++)
          if (w[jj][j]) dp[k][i][j] = (dp[k][i][j] + dp[k][i - 1][jj]) % M;
  for (int i = 1; i <= n + 2; i++) {
    for (int j = 1; j <= 3; j++) {
      long long tmp = 0;
      for (int k = 1; k <= 3; k++) tmp += dp[k][i][j];
      dp_l[i][j] = tmp % M;
    }
    for (int k = 1; k <= 3; k++) {
      long long tmp = 0;
      for (int j = 1; j <= 3; j++) tmp += dp[k][i][j];
      dp_r[k][i] = tmp % M;
    }
  }
  dp_full = 0;
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) dp_full = (dp_full + dp[i][n][j]) % M;
  set<segment> S;
  S.insert(segment{1, n + 1});
  fill(P, P + SZ + SZ, 1);
  modify(1, dp_full);
  while (m--) {
    int v, t;
    scanf("%d%d", &v, &t);
    if (!a[v] && t) {
      a[v] = t;
      set<segment>::iterator it = S.upper_bound(segment{v, 233});
      assert(it != S.begin());
      --it;
      assert(it->l <= v && v < it->r);
      segment tmp = *it;
      modify(tmp.l, 1);
      S.erase(it);
      check(v);
      check(v + 1);
      if (tmp.l != v) {
        segment left{tmp.l, v};
        modify(left.l, fuck(left));
        S.insert(left);
      }
      if (tmp.r != v + 1) {
        segment right{v + 1, tmp.r};
        modify(right.l, fuck(right));
        S.insert(right);
      }
    } else if (a[v] && t) {
      a[v] = t;
      check(v);
      check(v + 1);
      set<segment>::iterator it_r = S.upper_bound(segment{v, 233});
      set<segment>::iterator it_l = it_r;
      if (it_l == S.begin())
        it_l = S.end();
      else
        --it_l;
      if (it_l != S.end() && it_l->r == v) modify(it_l->l, fuck(*it_l));
      if (it_r != S.end() && it_r->l == v + 1) modify(it_r->l, fuck(*it_r));
    } else if (a[v] && !t) {
      a[v] = t;
      check(v);
      check(v + 1);
      set<segment>::iterator it_r = S.upper_bound(segment{v, 233});
      set<segment>::iterator it_l = it_r;
      if (it_l == S.begin())
        it_l = S.end();
      else
        --it_l;
      segment seg{v, v + 1};
      if (it_l != S.end() && it_l->r == v) {
        seg.l = it_l->l;
        modify(it_l->l, 1);
        S.erase(it_l);
      }
      if (it_r != S.end() && it_r->l == v + 1) {
        seg.r = it_r->r;
        modify(it_r->l, 1);
        S.erase(it_r);
      }
      modify(seg.l, fuck(seg));
      S.insert(seg);
    }
    printf("%d\n", P[1]);
  }
  return 0;
}
