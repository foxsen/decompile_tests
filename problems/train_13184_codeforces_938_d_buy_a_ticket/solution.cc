#include <bits/stdc++.h>
using namespace std;
long long power(long long, long long);
long long mpower(long long, long long);
long long BIT[1000009];
long long query(long long);
void update(long long, long long);
vector<pair<long long, long long>> graph[1000009];
long long vis[1000009];
long long dis[1000009];
long long inc[1000009];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b, w;
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  for (long long i = 1; i <= n; i++) {
    cin >> dis[i];
    inc[i] = dis[i];
    pq.push({dis[i], i});
  }
  while (!pq.empty()) {
    long long t = pq.top().second;
    pq.pop();
    if (vis[t]) continue;
    vis[t] = 1;
    for (pair<long long, long long> w : graph[t]) {
      long long u = w.first;
      long long wt = w.second;
      ;
      if (dis[u] > dis[t] + 2 * wt) {
        dis[u] = dis[t] + 2 * wt;
        pq.push({dis[u], u});
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << dis[i] << " ";
  }
  return 0;
}
void update(long long x, long long delta) {
  for (; x < 1000009; x += x & -x) BIT[x] += delta;
}
long long query(long long x) {
  long long sum = 0;
  for (; x > 0; x -= x & -x) sum += BIT[x];
  return sum;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = res * a;
    a = a * a;
    b = b / 2;
  }
  return res;
}
long long mpower(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
