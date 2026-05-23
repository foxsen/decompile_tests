#include <bits/stdc++.h>
using namespace std;
int f[1000000];
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (f[i] == 0) {
      for (int j = 2 * i; j <= n; j += i) {
        f[j] = i;
      }
    }
  }
  int ans = INT_MAX;
  int val;
  for (int i = n - f[n] + 1; i <= n; i++) {
    val = min(i, i - f[i] + 1);
    ans = min(ans, val);
  }
  cout << ans << endl;
  return 0;
}
