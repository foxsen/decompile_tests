#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, m;
  cin >> n >> m;
  long long int a[n], p[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      p[i] = a[i];
    else
      p[i] = p[i - 1] + a[i];
  }
  while (m--) {
    long long int x;
    cin >> x;
    long long int ps = lower_bound(p, p + n, x) - p;
    cout << ps + 1 << " ";
    if (ps == 0)
      cout << x << "\n";
    else if (p[ps] == x)
      cout << a[ps] << "\n";
    else
      cout << x - p[ps - 1] << "\n";
  }
  return 0;
}
