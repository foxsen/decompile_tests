#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  bool sorted = true;
  for (long long i = 1; i < n; ++i) {
    if (a[i] <= a[i - 1]) sorted = false;
  }
  if (sorted and n % 2) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  cout << endl;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
