#include <bits/stdc++.h>
using namespace std;
const long long MN = 2e3 + 20, INF = 1e9 + 2000;
long long a[MN][MN], dist[MN];
set<pair<long long, long long>> myset;
bool fix[MN];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, mn = INF;
  cin >> n;
  for (long long i = 0; i < n; i++)
    for (long long j = i + 1; j < n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
      mn = min(mn, a[i][j]);
    }
  for (long long i = 0; i < n; i++) {
    long long min_edge = INF;
    for (long long j = 0; j < n; j++) {
      if (i == j) continue;
      a[i][j] -= mn;
      min_edge = min(min_edge, a[i][j]);
    }
    dist[i] = min(INF, 2 * min_edge);
    myset.insert(make_pair(dist[i], i));
  }
  while (!myset.empty()) {
    pair<long long, long long> p = *myset.begin();
    myset.erase(myset.begin());
    long long u = p.second;
    fix[u] = true;
    for (long long v = 0; v < n; v++) {
      if (!fix[v]) {
        long long w = a[u][v];
        if (dist[v] > dist[u] + w) {
          myset.erase(myset.find(make_pair(dist[v], v)));
          dist[v] = dist[u] + w;
          myset.insert(make_pair(dist[v], v));
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) cout << dist[i] + ((n - 1) * mn) << endl;
  return 0;
}
