#include <bits/stdc++.h>
using namespace std;
int n, x1, y11, z, y12, x;
vector<pair<pair<int, int>, int>> taxi;
double nearest_taxi(int x, int y) {
  double ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    int x15 = taxi[i].first.first;
    int y15 = taxi[i].first.second;
    int v = taxi[i].second;
    double val =
        sqrt((y15 - y) * (y15 - y) + (x15 - x) * (x15 - x)) / (double)v;
    ans = min(ans, val);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> x >> y12;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y11 >> z;
    taxi.push_back({{x1, y11}, z});
  }
  cout << fixed << setprecision(10) << nearest_taxi(x, y12);
  return 0;
}
