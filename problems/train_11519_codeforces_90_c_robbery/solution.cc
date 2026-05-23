#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mn = 1e6, tmp;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    if (i % 2 == 0) mn = min(mn, tmp);
  }
  if (n % 2 == 0) {
    cout << 0 << endl;
  } else {
    long long res = 0;
    for (int i = 0; i < min(k, mn); i++) {
      res += m / ((n + 1) / 2);
    }
    res = min(res, mn);
    cout << res << endl;
  }
  return 0;
}
