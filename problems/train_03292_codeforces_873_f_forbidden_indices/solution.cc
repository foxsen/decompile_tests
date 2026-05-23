#include <bits/stdc++.h>
using namespace std;
int n;
char s[202020], forbid[202020];
struct node {
  int ch[26], fa, len;
} d[404040];
int las = 1, tot = 1;
int f[404040];
inline void add(char c, int w) {
  int lastnode = las;
  int newnode = las = ++tot;
  d[newnode].len = d[lastnode].len + 1;
  f[newnode] = w;
  int p;
  for (p = lastnode; p && !d[p].ch[c]; p = d[p].fa) d[p].ch[c] = newnode;
  if (!p) {
    d[newnode].fa = 1;
    return;
  }
  int nearc = d[p].ch[c];
  if (d[nearc].len == d[p].len + 1) {
    d[newnode].fa = nearc;
    return;
  }
  int midnode = ++tot;
  d[midnode] = d[nearc];
  d[midnode].len = d[p].len + 1;
  d[newnode].fa = d[nearc].fa = midnode;
  for (int pp = p; pp && d[pp].ch[c] == nearc; pp = d[pp].fa)
    d[pp].ch[c] = midnode;
}
int b[404040], topo[404040];
inline void topoprep() {
  for (int i = 1; i <= tot; ++i) b[d[i].len]++;
  for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
  for (int i = 1; i <= tot; ++i) topo[b[d[i].len]--] = i;
}
inline void updmax(long long &a, long long b) { a = b > a ? b : a; }
long long dp[404040];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  scanf("%s", forbid + 1);
  for (int i = 1; i <= n; ++i) add(s[i] - 'a', 1 - forbid[i] + '0');
  topoprep();
  for (int i = tot; i >= 2; --i) f[d[topo[i]].fa] += f[topo[i]];
  long long ans = 0;
  for (int i = 1; i <= tot; ++i) {
    ans = max(ans, (long long)d[i].len * f[i]);
  }
  printf("%lld\n", ans);
}
