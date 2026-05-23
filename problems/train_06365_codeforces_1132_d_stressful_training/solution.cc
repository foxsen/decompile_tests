#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2, class T3 = hash<T1>>
using umap = unordered_map<T1, T2, T3>;
template <class T>
using uset = unordered_set<T>;
template <class T>
using vec = vector<T>;
const long long infll = numeric_limits<long long>::max() >> 1;
const long long inf = numeric_limits<long long>::max() >> 5;
const long long N = 2e5 + 5;
long long n, k;
pair<long long, long long> p[N];
vec<pair<long long, long long>> v[N];
void input() {
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) {
    cin >> p[i].first;
  }
  for (long long i = 0; i < n; ++i) {
    cin >> p[i].second;
  }
}
bool test(long long q) {
  for (long long i = 0; i <= k + 2; ++i) {
    v[i].clear();
  }
  for (long long i = 0; i < n; ++i) {
    long long d = min(k, p[i].first / p[i].second);
    v[d].push_back(p[i]);
  }
  long long cnt = 0;
  for (long long i = 0; i < k - 1; ++i) {
    cnt++;
    for (pair<long long, long long> e : v[i]) {
      long long c = ceil((double)((i + 1) * e.second - e.first) / q);
      v[min(k, (e.first + c * q) / e.second)].push_back(
          {e.first + c * q, e.second});
      cnt -= c;
      if (cnt < 0) {
        return 0;
      }
    }
    v[i].clear();
  }
  return 1;
}
long long bin_search(long long l, long long r) {
  if (l == r) {
    return l;
  }
  long long q = l + r >> 1;
  if (test(q)) {
    return bin_search(l, q);
  } else {
    return bin_search(q + 1, r);
  }
}
void solve() {
  long long q = bin_search(0, inf);
  if (q == inf) {
    cout << "-1\n";
  } else {
    cout << q << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  solve();
}
