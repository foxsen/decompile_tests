#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<pair<long long, int>> adj[10 * MAXN];
long long dist[10 * MAXN];
int par[10 * MAXN];
int go1(int idx, int l, int r, int ds) {
  if (idx > 1) {
    int par = idx / 2;
    adj[par + ds].push_back({0, idx + ds});
  }
  if (l == r) {
    adj[idx + ds].push_back({0, l});
    return idx;
  }
  int m = (l + r) / 2;
  int ret =
      max(idx, max(go1(2 * idx, l, m, ds), go1(2 * idx + 1, m + 1, r, ds)));
  return ret;
}
void go2(int idx, int l, int r, int ds) {
  for (int i = l; i < (r + 1); ++i) {
    adj[i].push_back({0, idx + ds});
  }
  if (r > l) {
    int m = (l + r) / 2;
    go2(2 * idx, l, m, ds);
    go2(2 * idx + 1, m + 1, r, ds);
  }
}
void go3(int idx, int x, int y, int l, int r, function<void(int)> f) {
  if (y < l || x > r) return;
  if (x >= l && y <= r) {
    f(idx);
    return;
  }
  int m = (x + y) / 2;
  go3(2 * idx, x, m, l, r, f);
  go3(2 * idx + 1, m + 1, y, l, r, f);
}
void dijsktra(int src) {
  memset(dist, 0x3f3f3f3f, sizeof(dist));
  dist[src] = 0;
  par[src] = src;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({dist[src], src});
  while (!pq.empty()) {
    int u = pq.top().second;
    long long l = pq.top().first;
    pq.pop();
    if (dist[u] == l) {
      for (auto p : adj[u]) {
        long long ndist = l + p.first;
        if (ndist < dist[p.second]) {
          dist[p.second] = ndist;
          par[p.second] = u;
          pq.push({dist[p.second], p.second});
        }
      }
    }
  }
}
int main() {
  int n, m, src;
  scanf(" %d %d", &(n), &(m));
  scanf(" %d", &(src));
  --src;
  int ds1 = n - 1 + 5;
  int ds2 = go1(1, 0, n - 1, ds1) + ds1 + 5;
  go2(1, 0, n - 1, ds2);
  while (m--) {
    int tp;
    scanf(" %d", &(tp));
    if (tp == 1) {
      int u, v, w;
      scanf(" %d %d", &(u), &(v));
      scanf(" %d", &(w));
      adj[u - 1].push_back({w, v - 1});
    } else {
      int vtx, l, r, w;
      scanf(" %d %d", &(vtx), &(l));
      scanf(" %d %d", &(r), &(w));
      --l;
      --r;
      --vtx;
      go3(1, 0, n - 1, l, r, [=](int idx) {
        if (tp == 2) {
          adj[vtx].push_back({w, idx + ds1});
        } else {
          adj[idx + ds2].push_back({w, vtx});
        }
      });
    }
  }
  dijsktra(src);
  for (int i = 0; i < (n); ++i)
    printf("%lld%c", (dist[i] == 0x3f3f3f3f3f3f3f3fll ? -1 : dist[i]),
           " \n"[i == n - 1]);
  return 0;
}
