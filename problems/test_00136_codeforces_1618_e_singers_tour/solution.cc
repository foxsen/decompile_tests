#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
void solve() {
  long long int n;
  cin >> n;
  long long int b[n];
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  long long int t = (n * (n + 1)) / 2;
  if (sum % t) {
    cout << "NO\n";
    return;
  }
  long long int x = sum / t;
  long long int a[n];
  for (long long int i = (n - 1); i >= 0; i--) {
    long long int p = (b[i] - b[(i + 1) % n] + x);
    if (p % n != 0 || p <= 0) {
      cout << "NO\n";
      return;
    }
    a[(i + 1) % n] = p / n;
  }
  cout << "YES\n";
  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
