#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void sol() {
  long long x, y, k;
  cin >> x >> y >> k;
  cout << (k + y * k + x - 3) / (x - 1) + k << '\n';
}
int32_t main() {
  fast_io();
  long long t;
  cin >> t;
  while (t-- > 0) sol();
  return 0;
}
