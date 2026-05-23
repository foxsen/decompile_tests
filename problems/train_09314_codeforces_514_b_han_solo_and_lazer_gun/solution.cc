#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x0, y0;
  cin >> n >> x0 >> y0;
  map<double, int> mp;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    double m;
    if (x - x0 != 0)
      m = ((double)y - y0) / ((double)x - x0);
    else
      m = 1000;
    mp[m]++;
  }
  cout << mp.size();
  return 0;
}
