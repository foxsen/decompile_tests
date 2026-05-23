#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100010;
const long long mod = 1000000007;
const long double eps = 1e-9;
const long long inf = ((1ll << 31ll) - 1ll);
const long long INF = 2000000000000000000ll;
const long double pi = acos(-1);
long long qpow(long long b, long long e) {
  if (!e) return 1;
  if (e & 1) return qpow(b, e - 1) * b % mod;
  long long pwur = qpow(b, e >> 1);
  return pwur * pwur % mod;
}
long long modinv(long long x) { return qpow(x, mod - 2); }
long long n, p;
vector<long long> ans;
map<long long, long long> cnt;
vector<long long> v;
void update(long long id) {
  for (; id < 2000000000; id += (id & -id)) {
    cnt[id]++;
  }
}
long long query(long long id) {
  long long res = 0;
  for (; id > 0; id -= (id & -id)) {
    res += cnt[id];
  }
  return res;
}
bool can(long long x) {
  bool res = 1;
  long long q = query(x - 1), pt = 0;
  for (long long i = x; i < x + n; i++) {
    while (v[pt] <= i) pt++;
    if (pt <= i - x) res = 0;
  }
  return (res != 0);
}
bool first(long long x) {
  long long res = 1;
  long long q = query(x - 1), pt = 0;
  for (long long i = x; i < x + n; i++) {
    while (v[pt] <= i) pt++;
    if (pt <= i - x) res = 0;
    res = res * (pt - (i - x)) % p;
  }
  return (res != 0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(0);
  srand(time(NULL));
  cin >> n >> p;
  for (long long i = 1; i <= n; i++) {
    long long u;
    cin >> u;
    update(u);
    v.push_back(u);
  }
  sort(v.begin(), v.end());
  v.push_back(INF);
  long long l = 1, r = 1000000000 + 5;
  while (l < r) {
    long long mi = (l + r) >> 1;
    if (can(mi))
      r = mi;
    else
      l = mi + 1;
  }
  if (can(l - 1)) l--;
  if (!can(l)) l++;
  long long tl = l, tr = 1000000000 + 5;
  while (tl < tr) {
    long long mi = (tl + tr) >> 1;
    if (!first(mi))
      tr = mi;
    else
      tl = mi + 1;
  }
  if (first(tl + 1)) tl++;
  if (!first(tl)) tl--;
  for (long long i = l; i <= tl; i++) ans.push_back(i);
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i << ' ';
  cout << '\n';
  return 0;
}
