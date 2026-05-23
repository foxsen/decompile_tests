#include <bits/stdc++.h>
using namespace std;
template <class T>
struct rge {
  T b, e;
};
template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
}
struct debug {
  template <class T>
  debug& operator<<(const T&) {
    return *this;
  }
};
using ll = long long;
template <typename T>
void min_self(T& a, T b) {
  a = min(a, b);
}
template <typename T>
void max_self(T& a, T b) {
  a = max(a, b);
}
const int inf = 1e9 + 5;
int calc(int a, int b, int p) { return b / p - (a - 1) / p; }
vector<int> factor(int n) {
  vector<int> f;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      f.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    f.push_back(n);
  }
  return f;
}
void test_case() {
  int x, p, k;
  cin >> x >> p >> k;
  vector<int> f = factor(p);
  vector<pair<int, int>> contrib;
  int n = f.size();
  for (int s = 1; s < (1 << n); s++) {
    int c = __builtin_popcount(s) % 2 == 1 ? -1 : 1;
    int y = 1;
    for (int i = 0; i < n; i++) {
      if (s >> i & 1) {
        y *= f[i];
      }
    }
    contrib.emplace_back(c, y);
  }
  int lo = x + 1, hi = inf;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    int cnt = mid - x;
    for (pair<int, int> pp : contrib) {
      cnt += pp.first * calc(x + 1, mid, pp.second);
    }
    if (cnt >= k) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << hi << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
}
