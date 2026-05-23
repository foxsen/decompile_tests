#include <bits/stdc++.h>
using namespace std;
long long mod_v(long long num) {
  if (num >= 0)
    return (num % 1000000007);
  else
    return (num % 1000000007 + 1000000007) % 1000000007;
}
long long bigmod(long long b, long long p, long long m) {
  long long res = 1 % m, x = b % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
class node {
 public:
  int s, w;
  node(){};
  node(int s, int w) {
    this->s = s;
    this->w = w;
  };
};
bool operator<(node a, node b) {
  if (a.w < b.w)
    return true;
  else
    return false;
}
bool vol[100005] = {0};
int vis[100005] = {0};
vector<int> adj[100005];
int n;
bool solve(int q, int s, int d) {
  memset(vis, 0, sizeof(vis));
  vis[s] = q;
  priority_queue<node> pq;
  pq.push(node(s, q));
  while (!pq.empty()) {
    s = pq.top().s;
    pq.pop();
    if (s == d) return true;
    for (int i = 0, ns; i < adj[s].size(); i++) {
      ns = adj[s][i];
      if (ns == d) return true;
      if (vol[ns] == 1 && vis[ns] < q) {
        vis[ns] = q;
        pq.push(node(ns, vis[ns]));
      } else if (vis[ns] < vis[s] - 1) {
        vis[ns] = vis[s] - 1;
        pq.push(node(ns, vis[ns]));
      }
    }
  }
  return false;
}
int main() {
  int m, k, u, v, s, d;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &u);
    vol[u] = 1;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%d %d", &s, &d);
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (solve(mid, s, d))
      r = mid;
    else
      l = mid + 1;
  }
  if (l == n)
    printf("-1\n");
  else
    cout << l << endl;
}
