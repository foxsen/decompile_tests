#include <bits/stdc++.h>
using namespace std;
set<long long> s;
long long a[300005];
bool maximum(long long k, long long n) {
  if (k > 0 && a[k] < a[k - 1]) {
    return 0;
  }
  if (k < n - 1 && a[k] < a[k + 1]) {
    return 0;
  }
  return 1;
}
bool minimum(long long k, long long n) {
  if (k == n - 1 || k == 0) {
    return 0;
  }
  if (a[k] > a[k - 1] || a[k] > a[k + 1]) {
    return 0;
  }
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long sum = 0;
    long long n, q;
    cin >> n >> q;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      if (maximum(i, n)) {
        sum += a[i];
      }
      if (minimum(i, n)) {
        sum -= a[i];
      }
    }
    cout << sum << '\n';
    while (q--) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      for (long long i = -1; i <= 1; i++) {
        if (u + i < 0 || u + i >= n) {
          continue;
        }
        s.insert(u + i);
      }
      swap(u, v);
      for (long long i = -1; i <= 1; i++) {
        if (u + i < 0 || u + i >= n) {
          continue;
        }
        s.insert(u + i);
      }
      for (long long i : s) {
        if (maximum(i, n)) {
          sum -= a[i];
        }
        if (minimum(i, n)) {
          sum += a[i];
        }
      }
      swap(a[u], a[v]);
      for (long long i : s) {
        if (maximum(i, n)) {
          sum += a[i];
        }
        if (minimum(i, n)) {
          sum -= a[i];
        }
      }
      cout << sum << '\n';
      s.clear();
    }
  }
  return 0;
}
