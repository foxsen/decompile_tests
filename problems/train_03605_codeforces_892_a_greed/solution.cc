#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, sum = 0;
  cin >> n;
  long long int b[n];
  for (long long int i = 0; i < n; i += 1) {
    long long int val;
    cin >> val;
    sum += val;
  }
  for (long long int i = 0; i < n; i += 1) {
    cin >> b[i];
  }
  sort(b, b + n);
  if (b[n - 1] + b[n - 2] >= sum)
    cout << "YES";
  else
    cout << "NO";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) solve();
}
