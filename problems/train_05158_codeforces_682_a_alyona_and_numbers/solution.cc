#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, a, b;
  long long temp, ans = 0;
  cin >> n >> m;
  int sum = m + n;
  sum /= 5;
  sum *= 5;
  a = min(m, n);
  b = max(m, n);
  for (int i = 1; i <= a; i++) {
    if (sum) ans += (i + b) / 5 - i / 5;
  }
  cout << ans << endl;
  return 0;
}
