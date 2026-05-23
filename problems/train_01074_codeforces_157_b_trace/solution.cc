#include <bits/stdc++.h>
using namespace std;
int arr[104] = {0};
int main() {
  int i, j, k, t, n, m, a, b, c, x, y, z;
  double pi = 4.0 * atan(1.0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  double ans = 0.0;
  for (i = n; i > 1; i -= 2) {
    ans += pi * (arr[i] * arr[i] - arr[i - 1] * arr[i - 1]);
  }
  ans += pi * (arr[i] * arr[i]);
  printf("%0.10lf", ans);
  return 0;
}
