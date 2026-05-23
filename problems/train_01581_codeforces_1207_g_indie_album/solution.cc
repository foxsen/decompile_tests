#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long N = 4e5 + 10;
const long long M = 3e8 + 1;
const long long big = 1e18;
const long long shift = 1000;
const long long hsh2 = 1964325029;
const long long mod = 998244353;
const long double EPS = 1e-14;
const long long block = 700;
int n, m;
long long Z[N];
vector<pair<long long, long long> > q[N];
struct aho {
  int t[N][26], b[N], p[N], tp[N], k[N], cur = 2;
  int songs[N] = {1};
  bool term[N];
  void add1(string a, long long num) {
    long long v = 1;
    for (auto u : a) {
      long long ch = u - 'a';
      if (!t[v][ch]) b[cur] = ch, p[cur] = v, t[v][ch] = cur++;
      v = t[v][ch];
    }
    songs[num] = v;
    term[v] = 1;
  }
  void add2(long long j, long long z, long long num) {
    j = songs[j];
    if (!t[j][z]) b[cur] = z, p[cur] = j, t[j][z] = cur++;
    songs[num] = t[j][z];
  }
  void suflink(long long v) {
    if (p[v] != 1)
      k[v] = t[k[p[v]]][b[v]];
    else
      k[v] = 1;
    if (term[k[v]])
      tp[v] = k[v];
    else
      tp[v] = tp[k[v]];
    for (int i = 0; i < 26; i++) {
      if (t[v][i]) continue;
      t[v][i] = t[k[v]][i];
    }
  }
  void sufbld() {
    p[1] = 1;
    k[1] = 1;
    tp[1] = 1;
    for (int i = 0; i < 26; i++)
      if (!t[1][i]) t[1][i] = 1;
    queue<int> q;
    q.push(1);
    while (q.size()) {
      long long v = q.front();
      q.pop();
      for (int i = 0; i < 26; i++)
        if (t[v][i] && t[v][i] != 1) q.push(t[v][i]);
      if (v != 1) suflink(v);
    }
  }
  void upd(int z, short int d) {
    while (z != 1) Z[z] += d, z = tp[z];
  }
} rt[2];
long long answ[N];
void dfs(int a, int b) {
  rt[1].upd(b, 1);
  for (auto u : q[a]) answ[u.first] = Z[u.second];
  for (int i = 0; i < 26; i++) {
    if (rt[0].t[a][i]) dfs(rt[0].t[a][i], rt[1].t[b][i]);
  }
  rt[1].upd(b, -1);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, j, z; i <= n; i++) {
    char x;
    cin >> j;
    if (j == 1)
      j = 0, cin >> x;
    else
      cin >> j >> x;
    rt[0].add2(j, x - 'a', i);
  }
  cin >> m;
  string x;
  for (int i = 1, y; i <= m; i++) {
    cin >> y >> x;
    rt[1].add1(x, i);
    q[rt[0].songs[y]].push_back(make_pair(i, rt[1].songs[i]));
  }
  rt[1].sufbld();
  dfs(1, 1);
  for (int i = 1; i <= m; i++) cout << answ[i] << '\n';
}
