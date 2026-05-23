#include <bits/stdc++.h>
using namespace std;
long long a[200001], b[200001];
int main() {
  long long s = 0, s1 = 0, n, i, di = 0, mx = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    s = s + a[i];
    if (b[i] >= mx) {
      mx = b[i];
      di = i;
    }
  }
  sort(b + 1, b + n + 1);
  for (i = 1; i <= n; i++) {
    if (i == di) {
      cout << ((s - a[i]) * b[n - 1]) << " ";
    } else {
      cout << ((s - a[i]) * mx) << " ";
    }
  }
}
