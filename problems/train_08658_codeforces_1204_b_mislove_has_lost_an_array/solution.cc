#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 10;
const int minf = -1e9;
void solve() {
  long long n, l, r;
  cin >> n >> l >> r;
  long long minSum = 0, maxSum = 0;
  long long x = 1;
  for (int i = 0; i < min(l, n); i++) {
    minSum += x;
    x *= 2;
    ;
  }
  for (int i = min(l, n); i < n; i++) {
    minSum++;
  }
  x = 1;
  for (int i = 0; i < min(r, n); i++) {
    maxSum += x;
    x *= 2;
    ;
  }
  x /= 2;
  for (int i = min(r, n); i < n; i++) {
    maxSum += x;
  }
  cout << minSum << " " << maxSum << "\n";
}
void clear() {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int z = 1;
  for (int i = 0; i < z; i++) {
    solve();
    clear();
  }
}
