#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long linf = (long long)1e18;
const int mod = (int)1e9 + 7;
const long double eps = (long double)1e-8;
const int maxn = (int)5e5 + 5;
const long double pi = acos(-1);
int n, m, cnt_cyc;
int t[maxn], cyc[maxn], tup[maxn];
int ans[maxn], ans1[maxn], cyc_head[maxn], p[maxn], d[maxn], dc[maxn],
    dc_up[maxn];
vector<int> a[maxn], cycv[maxn];
void dfs0(int v, int pr = -1) {
  p[v] = pr;
  t[v] = 1;
  tup[v] = 1;
  for (auto to : a[v]) {
    if (to == pr) continue;
    if (t[to] && tup[to] == 0) continue;
    if (t[to]) {
      cnt_cyc++;
      cyc[to] = cnt_cyc;
      int x = v;
      cycv[cnt_cyc].push_back(to);
      while (cyc[x] == 0) {
        cyc[x] = cnt_cyc;
        cycv[cnt_cyc].push_back(x);
        x = p[x];
      }
      cyc_head[cnt_cyc] = to;
    } else {
      dfs0(to, v);
    }
  }
  if (cyc[v] == 0) {
    cnt_cyc++;
    cyc[v] = cnt_cyc;
    cyc_head[cnt_cyc] = v;
    cycv[cnt_cyc].push_back(v);
  }
  tup[v] = 0;
}
void dfs_cyc0(int cv, int cpr = -1) {
  for (auto v : cycv[cv]) {
    for (auto to : a[v]) {
      if (cyc[to] == cpr || cyc[to] == cv) continue;
      dfs_cyc0(cyc[to], cv);
      d[v] = max(d[v], dc[cyc[to]] + 1);
    }
  }
  for (auto i = 0; i < ((int)(cycv[cv]).size()); ++i) {
    dc[cv] = max(dc[cv], d[cycv[cv][i]] + min(i, ((int)(cycv[cv]).size()) - i));
  }
}
void dfs_cyc1(int cv, int cpr = -1) {
  if (((int)(cycv[cv]).size()) >= 3) {
    vector<int> b;
    for (auto j = 0; j < 3; ++j) {
      for (auto i = 0; i < ((int)(cycv[cv]).size()); ++i) {
        b.push_back(d[cycv[cv][i]]);
      }
    }
    int l, r;
    l = ((int)(cycv[cv]).size()) - ((int)(cycv[cv]).size()) / 2;
    r = ((int)(cycv[cv]).size()) + ((int)(cycv[cv]).size()) / 2 -
        (((int)(cycv[cv]).size()) % 2 == 0);
    multiset<int, greater<int>> ql, qr;
    int pl = 0, pr = 0;
    for (auto i = l; i <= ((int)(cycv[cv]).size()) - 1; ++i) {
      ql.insert(b[i] + ((int)(cycv[cv]).size()) - i);
    }
    for (auto i = ((int)(cycv[cv]).size()) + 1; i <= r; ++i) {
      qr.insert(b[i] + i - ((int)(cycv[cv]).size()));
    }
    for (auto i = ((int)(cycv[cv]).size());
         i <= 2 * ((int)(cycv[cv]).size()) - 1; ++i) {
      int v = cycv[cv][i - ((int)(cycv[cv]).size())];
      ans1[v] = max(*ql.begin() + pl, *qr.begin() + pr);
      ql.erase(ql.find(i - l + b[l] - pl));
      ++pl;
      ++l;
      ql.insert(1 + b[i] - pl);
      qr.erase(qr.find(1 + b[i + 1] - pr));
      --pr;
      ++r;
      qr.insert(r - (i + 1) + b[r] - pr);
    }
    for (auto i = 0; i < ((int)(cycv[cv]).size()); ++i) {
      int v = cycv[cv][i];
      ans1[v] = max(ans1[v], min(i, ((int)(cycv[cv]).size()) - i) + dc_up[cv]);
      ans[v] = max(d[v], ans1[v]);
    }
  } else {
    for (auto i = 0; i < ((int)(cycv[cv]).size()); ++i) {
      int v = cycv[cv][i];
      ans1[v] = min(i, ((int)(cycv[cv]).size()) - i) + dc_up[cv];
      for (auto j = 0; j < ((int)(cycv[cv]).size()); ++j) {
        if (i == j) continue;
        int u = cycv[cv][j];
        int dist =
            min(abs(i - j), min(i, j) + ((int)(cycv[cv]).size()) - max(i, j));
        ans1[v] = max(ans1[v], d[u] + dist);
      }
      ans[v] = max(d[v], ans1[v]);
    }
  }
  for (auto v : cycv[cv]) {
    multiset<int> qm;
    for (auto to : a[v]) {
      if (cyc[to] == cpr || cyc[to] == cv) continue;
      qm.insert(-(dc[cyc[to]] + 1));
      if (((int)(qm).size()) > 2) qm.erase(++(++qm.begin()));
    }
    for (auto to : a[v]) {
      if (cyc[to] == cpr || cyc[to] == cv) continue;
      if (((int)(qm).size()) == 1) {
        dc_up[cyc[to]] = ans1[v] + 1;
      } else {
        auto it = qm.begin();
        if (dc[cyc[to]] + 1 == -*it) ++it;
        dc_up[cyc[to]] = max(ans1[v], -*it) + 1;
      }
      dfs_cyc1(cyc[to], cv);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (auto i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  memset((cyc), 0, sizeof(cyc));
  cnt_cyc = 0;
  memset((t), 0, sizeof(t));
  dfs0(0);
  memset((ans), 0, sizeof(ans));
  memset((ans1), 0, sizeof(ans1));
  memset((d), 0, sizeof(d));
  memset((dc), 0, sizeof(dc));
  memset((dc_up), 0, sizeof(dc_up));
  dfs_cyc0(cyc[0]);
  dfs_cyc1(cyc[0]);
  for (auto i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
