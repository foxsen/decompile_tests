#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
using ll = long long;
const long long maxn = 1 << 20, mod = 998244353;
long long p[maxn], r[maxn], sm[maxn];
long long n, a[maxn], act[maxn];
long long res = 0;
long long par(long long v) { return p[v] ? p[v] = par(p[v]) : v; }
void unite(long long i, long long j) {
  if (!act[i] || !act[j]) return;
  i = par(i), j = par(j);
  if (i == j) return;
  if (r[i] < r[j]) swap(i, j);
  p[j] = i;
  r[i] = j;
  sm[i] += sm[j];
  res = max(res, sm[i]);
}
void activ(long long i, long long v) {
  act[i] = 1;
  res = max(res, sm[i] = v);
  unite(i, i - 1);
  unite(i, i + 1);
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  vector<long long> ord(n), ans;
  for (auto &i : ord) cin >> i;
  reverse(ord.begin(), ord.end());
  for (auto &i : ord) {
    ans.push_back(res);
    activ(i, a[i]);
  }
  reverse(ans.begin(), ans.end());
  for (auto &i : ans) cout << i << '\n';
}
