#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, B = 350;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m, a[N], p[N], pos[N], L[N], R[N], size;
long long f[N], ans;
inline bool cmp(int i, int j) { return a[i] < a[j]; }
struct block {
  int l, r, q[B];
  long long k, b;
  inline long long calc(int i) { return f[i] + k * a[i] + b; }
  inline long double slope(int i, int j) {
    if (a[i] == a[j]) return f[i] > f[j] ? -inf : inf;
    return 1.0L * (f[i] - f[j]) / (a[i] - a[j]);
  }
  inline void build(int x) {
    for (int i = L[x]; i <= R[x]; i++) f[i] += k * a[i] + b;
    k = b = r = 0;
    l = 1;
    for (int i = L[x]; i <= R[x]; i++) {
      while (l < r && slope(q[r - 1], q[r]) < slope(q[r], p[i])) r--;
      q[++r] = p[i];
    }
  }
  inline pair<long long, int> query(void) {
    while (l < r && calc(q[l]) <= calc(q[l + 1])) l++;
    return make_pair(calc(q[l]), q[l]);
  }
} t[B];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  m = sqrt(n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) f[i] = a[i];
  for (int i = 1; i <= n; i++) pos[i] = (i - 1) / m + 1;
  for (int i = 1; i <= n; i++) p[i] = i;
  size = pos[n];
  for (int i = 1; i <= size; i++) {
    L[i] = R[i - 1] + 1;
    R[i] = min(n, i * m);
    for (int j = L[i]; j <= R[i]; j++) pos[j] = i;
    sort(p + L[i], p + R[i] + 1, cmp);
  }
  for (int i = 1; i <= size; i++) t[i].build(i);
  while (true) {
    pair<long long, int> res = make_pair(0ll, 0);
    for (int i = 1; i <= size; i++) res = max(res, t[i].query());
    if (!res.first) {
      cout << ans << endl;
      return 0;
    }
    ans += res.first;
    f[res.second] = -inf;
    for (int i = 1; i < pos[res.second]; i++) t[i].b += a[res.second];
    for (int i = L[pos[res.second]]; i < res.second; i++) f[i] += a[res.second];
    for (int i = res.second + 1; i <= R[pos[res.second]]; i++) f[i] += a[i];
    for (int i = pos[res.second] + 1; i <= size; i++) t[i].k++;
    t[pos[res.second]].build(pos[res.second]);
  }
  return 0;
}
