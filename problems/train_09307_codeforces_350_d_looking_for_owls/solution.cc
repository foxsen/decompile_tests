#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("fast-math")
using namespace std;
const long long INF = 2e9;
const long long INFll = 2e18;
const long long BASE1 = 179;
const long long BASE2 = 653;
const long long MOD = 1e9 + 7;
const long long MAXN = 1e5 + 10;
const long double PI = 3.1415926535;
const long double EPS = 1e-10;
struct line {
  long long A, B, C;
  line(long long A, long long B, long long C) : A(A), B(B), C(C){};
};
struct event {
  long long t;
  long double x;
  event() {
    t = -1;
    x = -1;
  }
  event(long long t, long double x) : t(t), x(x){};
};
long long gcd(long long a, long long b) {
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
pair<pair<long long, long long>, long long> normal(long long A, long long B,
                                                   long long C) {
  if (A < 0)
    A *= -1, B *= -1, C *= -1;
  else if (A == 0 && B < 0)
    A *= -1, B *= -1, C *= -1;
  long long g = gcd(abs(A), gcd(abs(B), abs(C)));
  A /= g, B /= g, C /= g;
  return make_pair(make_pair(A, B), C);
}
bool cmp(event& a, event& b) { return a.x < b.x || a.x == b.x && a.t < b.t; }
void solve() {
  long long n, m;
  cin >> n >> m;
  map<pair<pair<long long, long long>, long long>, vector<event>> dop;
  for (long long i = 0; i < (n); i++) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long A = y2 - y1, B = x1 - x2, C = -A * x1 - B * y1;
    pair<pair<long long, long long>, long long> l = normal(A, B, C);
    if (dop.find(l) == dop.end())
      dop[l] = {event(-1, min(x1, x2)), event(1, max(x1, x2))};
    else {
      dop[l].emplace_back(event(-1, min(x1, x2)));
      dop[l].emplace_back(event(1, max(x1, x2)));
    }
  }
  vector<long long> x(m), y(m), r(m);
  for (long long i = 0; i < (m); i++) cin >> x[i] >> y[i] >> r[i];
  long long dcnt = 0;
  for (long long i = 0; i < (m); i++) {
    for (long long j = 0; j < (i); j++) {
      if (r[i] != r[j]) continue;
      long long d =
          ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j]));
      if (d <= 4 * ((r[i]) * (r[i]))) continue;
      long long xm = x[i] + x[j], ym = y[i] + y[j];
      long long A1 = y[j] - y[i], B1 = x[i] - x[j];
      long long A = 2 * B1, B = -2 * A1, C = -B1 * xm + A1 * ym;
      pair<pair<long long, long long>, long long> l = normal(A, B, C);
      if (dop.find(l) == dop.end()) {
        continue;
      } else {
        dop[l].emplace_back(event(0, xm / (long double)2));
        dcnt++;
      }
    }
  }
  long long res = 0;
  for (auto [line, v] : dop) {
    sort(v.begin(), v.end(), cmp);
    long long bal = 0;
    for (event e : v) {
      if (e.t == -1)
        bal++;
      else if (e.t == 1)
        bal--;
      else {
        0;
        res += bal;
      }
    }
  }
  cout << res << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  long long t = 1;
  while (t--) solve();
  return 0;
}
