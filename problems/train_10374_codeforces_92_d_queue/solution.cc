#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class Ty>
Ty randint(Ty a, Ty b) {
  return uniform_int_distribution<Ty>(a, b)(rng);
}
template <class T>
void DBG(T&& x) {
  cerr << x << " ";
}
template <class T, class... Args>
void DBG(T&& x, Args&&... args) {
  DBG(x);
  DBG(args...);
}
template <class num>
inline void rd(num& x) {
  cin >> x;
}
template <class Ty, class... Args>
inline void rd(Ty& x, Args&... args) {
  rd(x);
  rd(args...);
}
template <class num>
inline void print(num&& x) {
  cout << x;
}
template <class Ty, class... Args>
inline void print(Ty&& x, Args&&... args) {
  print(x);
  print(' ');
  print(args...);
}
const int MAXN = 1e5 + 5;
int seg[4 * MAXN], pos[MAXN];
void build(int p, int i, int j) {
  if (i == j)
    seg[p] = pos[i];
  else {
    int m = (i + j) / 2;
    build(p + p, i, m);
    build(p + p + 1, m + 1, j);
    seg[p] = max(seg[p + p], seg[p + p + 1]);
  }
}
int query(int p, int i, int j, int l, int r) {
  if (i > r || j < l || l > r) return -1;
  if (i >= l && j <= r) return seg[p];
  int m = (i + j) / 2;
  return max(query(p + p, i, m, l, r), query(p + p + 1, m + 1, j, l, r));
}
inline void run_test(int test_number) {
  int n;
  rd(n);
  vector<int> a(n), allx;
  for (int i = 0; i < n; i++) rd(a[i]), allx.push_back(a[i]);
  sort(begin(allx), end(allx));
  allx.erase(unique(begin(allx), end(allx)), end(allx));
  memset(pos, -1, sizeof(pos));
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(begin(allx), end(allx), a[i]) - allx.begin();
    pos[a[i]] = i;
  }
  int N = allx.size();
  build(1, 0, N - 1);
  for (int i = 0; i < n; i++) {
    int ans = query(1, 0, N - 1, 0, a[i] - 1);
    if (ans > i)
      ans = ans - i - 1;
    else
      ans = -1;
    cout << ans << " \n"[i == n - 1];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests = 1;
  for (int i = 1; i <= n_tests; i++) run_test(i);
}
