#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, h, x, y, i, j, c = 0, ans = 0;
  cin >> n >> h;
  for (int i = 1; i < n; i++) printf("%.10f ", h * sqrt(1. * i / n));
  puts("");
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
