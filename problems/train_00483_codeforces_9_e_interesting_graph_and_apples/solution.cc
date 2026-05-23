#include <bits/stdc++.h>
using namespace std;
void fun() {}
long long int __gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
long long int poww(long long int a, long long int b, long long int md) {
  if (b < 0) return 0;
  if (a == 0) return 0;
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (1ll * res * a) % md;
    }
    a = (1ll * a * a) % md;
    b >>= 1;
  }
  return res;
}
long long int divide(long long int a, long long int b, long long int md) {
  long long int rr = a * (poww(b, md - 2, md));
  rr %= md;
  return rr;
}
const long long int size = 55;
long long int n, m;
long long int degree[size];
long long int parent[size];
long long int findp(long long int node) {
  if (parent[node] == node) return node;
  return parent[node] = findp(parent[node]);
}
void unite(long long int x, long long int y) {
  x = findp(x), y = findp(y);
  parent[y] = x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fun();
  cin >> n >> m;
  if (n == 1) {
    if (m == 1) {
      cout << "YES\n0\n";
    } else if (m > 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n1\n1 1\n";
    }
    return 0;
  }
  bool hasCycle = false;
  for (long long int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  for (long long int i = 1; i <= m; i++) {
    long long int u, v;
    cin >> u >> v;
    degree[u]++;
    degree[v]++;
    if (findp(u) == findp(v)) {
      hasCycle = true;
    } else {
      unite(u, v);
    }
  }
  long long int maxdegree = 0, mindegree = 1e9;
  for (long long int i = 1; i <= n; i++) {
    maxdegree = max(maxdegree, degree[i]);
    mindegree = min(mindegree, degree[i]);
  }
  long long int components = 0;
  for (long long int i = 1; i <= n; i++) {
    if (parent[i] == i) components++;
  }
  if (maxdegree == 2 && mindegree == 2 && n == m && components == 1) {
    cout << "YES\n0\n";
    return 0;
  }
  if (maxdegree > 2 || hasCycle || m >= n) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n" << n - m << '\n';
  for (long long int i = 1; i <= n && m - 1 < n; i++) {
    for (long long int j = i + 1; j <= n && m - 1 < n; j++) {
      if (findp(i) != findp(j) && degree[i] < 2 && degree[j] < 2) {
        degree[i]++;
        degree[j]++;
        cout << i << ' ' << j << '\n';
        m++;
        unite(i, j);
      }
    }
  }
  long long int node1 = -1;
  for (long long int i = 1; i <= n; i++) {
    if (degree[i] == 1 && node1 != -1) {
      cout << node1 << ' ' << i << '\n';
    } else if (degree[i] == 1) {
      node1 = i;
    }
  }
  return 0;
}
