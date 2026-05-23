#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
long long m, k, p;
vector<long long> g[100010];
long long cost[100010];
long long acum[100010];
long long depth[100010];
long long key;
long long maxD;
long long calc(long long idx, long long mid) {
  return ((acum[idx + 1] - acum[mid]) + depth[idx] * (idx - mid + 1));
}
void bfs() {
  queue<pair<long long, pair<long long, long long> > > q;
  q.push(make_pair(0, make_pair(-1, 0)));
  while (!q.empty()) {
    pair<long long, pair<long long, long long> > avfd = q.front();
    q.pop();
    long long av = avfd.first;
    long long af = avfd.second.first;
    long long ad = avfd.second.second;
    maxD = max(maxD, ad);
    cost[key] = -ad;
    depth[key] = ad;
    key++;
    for (int i = 0; i < (int)g[av].size(); i++) {
      long long nv = g[av][i];
      if (nv != af) {
        q.push(make_pair(nv, make_pair(av, ad + 1)));
      }
    }
  }
}
int main() {
  cin >> m >> k >> p;
  for (int i = 0; i < (int)m - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  maxD = 0;
  key = 0;
  bfs();
  assert(key == m);
  acum[0] = 0;
  for (int i = 0; i < (int)m; i++) {
    acum[i + 1] = acum[i] + cost[i];
  }
  long long res = 0;
  for (long long l = 1; l <= maxD; l++) {
    long long lo = 1;
    long long hi = m;
    while (lo < hi - 1) {
      long long mid = (lo + hi) / 2;
      if (depth[mid] <= l)
        lo = mid;
      else
        hi = mid;
    }
    long long idx = lo;
    lo = 0;
    hi = idx;
    while (lo < hi - 1) {
      long long mid = (lo + hi) / 2;
      if (calc(idx, mid) <= p)
        hi = mid;
      else
        lo = mid;
    }
    res = max(res, idx - hi + 1);
  }
  cout << min(res, k) << endl;
  return 0;
}
