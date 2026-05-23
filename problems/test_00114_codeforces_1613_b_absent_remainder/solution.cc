#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a, a + n);
  for (i = 1; i < n / 2 + 1; i++) cout << a[i] << " " << a[0] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
