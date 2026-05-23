#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long n, T, t[N], x[N], sa, sb;
long double ans;
vector<pair<long long, long long> > a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> T;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    if (t[i] == T)
      ans += x[i];
    else {
      if (t[i] < T) {
        a.push_back({T - t[i], x[i]});
        sa += (T - t[i]) * x[i];
      }
      if (t[i] > T) {
        b.push_back({t[i] - T, x[i]});
        sb += (t[i] - T) * x[i];
      }
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long can = min(sa, sb);
  for (int i = 0; i < a.size(); i++) {
    if (can < a[i].first * a[i].second) {
      ans += 1.0 * can / a[i].first;
      break;
    }
    can -= a[i].first * a[i].second;
    ans += a[i].second;
  }
  can = min(sa, sb);
  for (int i = 0; i < b.size(); i++) {
    if (can < b[i].first * b[i].second) {
      ans += 1.0 * can / b[i].first;
      break;
    }
    can -= b[i].first * b[i].second;
    ans += b[i].second;
  }
  cout << fixed << setprecision(10) << ans;
  return 0;
}
