#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
long long n;
double calculate(double x) {
  double radius = 0.0;
  for (long long i = 0; i < n; i++) {
    double xi = v[i].first;
    double yi = v[i].second;
    radius = max(radius,
                 abs((1.0 * (xi - x) * (xi - x) + 1.0 * yi * yi) / (2.0 * yi)));
  }
  return radius;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  bool okay1 = false;
  bool okay2 = false;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    if (y <= 0) {
      okay1 = true;
    }
    if (y > 0) {
      okay2 = true;
    }
    v.push_back(make_pair(x, y));
  }
  if (okay1 && okay2) {
    cout << -1;
    return 0;
  }
  double low = -100000000;
  double high = 100000000;
  for (long long i = 0; i < 100; i++) {
    double l1 = low + (high - low) / 3;
    double l2 = high + (low - high) / 3;
    if (calculate(l1) < calculate(l2)) {
      high = l2;
    } else
      low = l1;
  }
  cout << setprecision(18) << fixed << calculate(low);
}
