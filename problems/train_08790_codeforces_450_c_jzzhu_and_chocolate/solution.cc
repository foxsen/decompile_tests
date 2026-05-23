#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  if (n > m) swap(n, m);
  if (k > n + m - 2) {
    cout << -1;
    return 0;
  }
  if (k < n)
    cout << max(m * (n / (k + 1)), n * (m / (k + 1)));
  else if (k >= n && k < m)
    cout << n * (m / (k + 1));
  else {
    long long y = m;
    long long x = k + 2 - m;
    cout << (n / x) * (m / y);
  }
  return 0;
}
