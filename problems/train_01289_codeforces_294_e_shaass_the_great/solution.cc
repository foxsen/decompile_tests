#include <bits/stdc++.h>
using namespace std;
const long long inf = 2147483647;
long long read() {
  long long first = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    first = first * 10 + ch - '0';
    ch = getchar();
  }
  return first * f;
}
void print(long long first) {
  if (first < 0) putchar('-'), first = -first;
  short a[20] = {}, sz = 0;
  while (first > 0) a[sz++] = first % 10, first /= 10;
  if (sz == 0) putchar('0');
  for (long long i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
long long n;
vector<pair<long long, long long> > adj[5555];
struct edge {
  long long fr, tt, len;
} ed[5555];
long long ban;
long long dep[5555];
long long sz[5555];
long long sum[5555];
long long vis[5555];
long long res;
void dfs(long long u, long long pa, long long tag) {
  vis[u] = tag;
  for (long long i = 0; i < adj[u].size(); i++) {
    long long v = adj[u][i].first;
    if (v == pa || v == ban) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u, tag);
    sz[u] += sz[v];
    sum[u] += sum[v] + sz[v] * adj[u][i].second;
  }
  sz[u]++;
}
void calc(long long u, long long pa, long long root) {
  for (long long i = 0; i < adj[u].size(); i++) {
    long long v = adj[u][i].first;
    if (v == pa || v == ban) continue;
    sum[v] = sum[u] + (sz[root] - sz[v] - sz[v]) * adj[u][i].second;
    calc(v, u, root);
  }
}
long long doit(long long nw) {
  for (long long i = 1; i <= n; i++) vis[i] = 0;
  dep[nw] = 0;
  dfs(nw, -1, nw);
  calc(nw, -1, nw);
  long long mx = 1e18;
  int mxi;
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == nw) {
      if (mx > sum[i]) {
        mx = sum[i];
        mxi = i;
      }
    }
  }
  long long par = 0;
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == nw) {
      par += sum[i];
    }
  }
  res += par / 2;
  return mxi;
}
int main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    long long fr = read(), tt = read(), len = read();
    ed[i] = {fr, tt, len};
    adj[fr].push_back(make_pair(tt, len));
    adj[tt].push_back(make_pair(fr, len));
  }
  long long ans = 1e18;
  for (long long i = 1; i < n; i++) {
    memset(sz, 0, sizeof(sz));
    memset(dep, 0, sizeof(dep));
    memset(sum, 0, sizeof(sum));
    res = 0;
    long long u = ed[i].fr;
    long long v = ed[i].tt;
    ban = v;
    long long a = doit(u);
    ban = u;
    long long b = doit(v);
    res += sum[a] * sz[v] + sum[b] * sz[u] + ed[i].len * sz[u] * sz[v];
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}
