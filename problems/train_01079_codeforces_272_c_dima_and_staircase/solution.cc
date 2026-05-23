#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n;
  long long arr[n];
  for (long long& el : arr) cin >> el;
  cin >> m;
  long long hi = 0;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    --x;
    long long res = max(hi, arr[x]);
    cout << res << "\n";
    hi = max(res + y, hi);
  }
  return 0;
}
