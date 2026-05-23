#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, i;
  cin >> n >> a >> b >> c;
  int ans[n + 1];
  for (i = 0; i <= n; i++) ans[i] = -52464164;
  ans[0] = 0;
  for (i = 1; i <= n; i++) {
    if (i >= a) ans[i] = ans[i - a] + 1;
    if (i >= b) {
      ans[i] = max(ans[i], ans[i - b] + 1);
    }
    if (i >= c) {
      ans[i] = max(ans[i], ans[i - c] + 1);
    }
  }
  cout << max(0, ans[n]);
}
