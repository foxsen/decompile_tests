#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
const long long INF = 1e18;
long long values[N];
struct Line {
  long long k, m;
  Line(long long _k = 0, long long _m = 0) {
    k = _k;
    m = _m;
  }
  long long Get(long long val) { return k * val + m; }
};
struct LiChao_max {
  Line t[4 * N];
  bool vis[4 * N];
  void Set(Line v, int c, int ss, int se) {
    if (!vis[c]) {
      vis[c] = true;
      t[c] = v;
      return;
    }
    if (t[c].Get(values[ss]) >= v.Get(values[ss]) &&
        t[c].Get(values[se]) >= v.Get(values[se]))
      return;
    if (t[c].Get(values[ss]) < v.Get(values[ss]) &&
        t[c].Get(values[se]) < v.Get(values[se])) {
      t[c] = v;
      return;
    }
    int mid = (ss + se) >> 1;
    if (t[c].Get(values[ss]) >= v.Get(values[ss]) &&
        t[c].Get(values[mid]) >= v.Get(values[mid])) {
      Set(v, c << 1 | 1, mid + 1, se);
    } else if (t[c].Get(values[ss]) >= v.Get(values[ss]) &&
               t[c].Get(values[mid]) <= v.Get(values[mid])) {
      swap(t[c], v);
      Set(v, c << 1, ss, mid);
    } else if (t[c].Get(values[ss]) <= v.Get(values[ss]) &&
               t[c].Get(values[mid]) >= v.Get(values[mid])) {
      Set(v, c << 1, ss, mid);
    } else {
      swap(t[c], v);
      Set(v, c << 1 | 1, mid + 1, se);
    }
  }
  long long Get(long long ind, int c, int ss, int se) {
    if (!vis[c]) return -INF;
    long long sol = t[c].Get(ind);
    if (ss == se) return sol;
    int mid = (ss + se) >> 1;
    if (ind <= values[mid])
      return max(sol, Get(ind, c << 1, ss, mid));
    else
      return max(sol, Get(ind, c << 1 | 1, mid + 1, se));
  }
} Chao1, Chao2;
long long a[N], n, ans, S[N], sum;
vector<long long> b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    S[i] = S[i - 1] + a[i];
    ans += a[i] * 1LL * i;
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int sz = (int)b.size();
  for (int i = 0; i < sz; i++) values[i + 1] = b[i];
  sum = ans;
  Chao1.Set(Line(n, -S[n]), 1, 1, sz);
  for (int i = n - 1; i >= 1; i--) {
    long long sol = Chao1.Get(a[i], 1, 1, sz) + S[i] - a[i] * 1LL * i;
    ans = max(ans, sum + sol);
    Chao1.Set(Line(i, -S[i]), 1, 1, sz);
  }
  Chao2.Set(Line(1, 0), 1, 1, sz);
  for (int i = 2; i <= n; i++) {
    long long sol = Chao2.Get(a[i], 1, 1, sz) + S[i - 1] - a[i] * 1LL * i;
    ans = max(ans, sum + sol);
    Chao2.Set(Line(i, -S[i - 1]), 1, 1, sz);
  }
  cout << ans;
  return 0;
}
