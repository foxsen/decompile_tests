#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<double> vect1;
  vector<pair<double, double>> vect;
  for (long long i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    vect.push_back({x, y});
    double ans = atan2(y, x);
    ans = (ans * (180 * 1.0)) / 3.14159265358979323846;
    vect1.push_back(ans);
  }
  sort(vect1.begin(), vect1.end());
  double mi = vect1[n - 1] - vect1[0];
  for (long long i = 0; i < n - 1; i++) {
    mi = min(mi, double(360 - (vect1[i + 1] - vect1[i])));
  }
  cout << fixed << setprecision(8) << mi << '\n';
  return 0;
}
