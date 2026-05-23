#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powerMod(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
string binary(long long s) {
  string res = "";
  while (s != 0) {
    res += (char)('0' + s % 2);
    s /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}
vector<vector<pair<long long, long long> > > adj;
vector<bool> vis;
vector<long long> cc;
vector<pair<long long, long long> > edges;
map<pair<long long, long long>, long long> mp;
long long n;
long long dfs(int y) {
  vis[y] = true;
  long long k = 1LL;
  for (pair<long long, long long> p : adj[y]) {
    if (!vis[p.first]) {
      long long x = dfs(p.first);
      cc[p.second] = min(n - x, x);
      k += x;
    }
  }
  return k;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t, m, i, j, k, l, p, mx, mn;
  cin >> t;
  while (t--) {
    cin >> n;
    n *= 2LL;
    adj.resize(n);
    vis.resize(n, false);
    cc.resize(n - 1LL, 0LL);
    edges.resize(n - 1LL);
    set<pair<long long, pair<long long, long long> > > s;
    for (i = 0; i < n - 1LL; i++) {
      cin >> j >> k >> l;
      --j, --k;
      if (j > k) swap(j, k);
      edges[i] = {j, k};
      adj[j].push_back({k, i});
      adj[k].push_back({j, i});
      mp[edges[i]] = l;
    }
    dfs(0LL);
    mx = 0LL;
    mn = 0LL;
    for (i = 0; i < n - 1; i++) {
      mx += mp[edges[i]] * cc[i];
      mn += mp[edges[i]] * (cc[i] % 2LL);
    }
    cout << mn << " " << mx << "\n";
    adj.clear();
    vis.clear();
    cc.clear();
    edges.clear();
    mp.clear();
  }
  return 0;
}
