#include <bits/stdc++.h>
using namespace std;
inline void splay(int &v) {
  v = 0;
  char c = 0;
  int p = 1;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 3) + (v << 1) + c - '0';
    c = getchar();
  }
  v *= p;
}
const int N = 100010;
int n, a[N], b[N], dp[5], v[N], ans;
int main() {
  splay(n);
  for (int i = 1; i <= n; i++) {
    splay(v[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (v[i] == 1);
  }
  for (int i = n; i >= 1; i--) {
    b[i] = b[i + 1] + (v[i] == 2);
  }
  for (int l = 1; l <= n; l++) {
    int now = 0;
    dp[1] = dp[2] = 0;
    for (int r = l; r <= n; r++) {
      if (v[r] == 1) {
        dp[1] = max(dp[1], dp[2]) + 1;
      } else {
        dp[2] = dp[2] + 1;
      }
      ans = max(ans, a[l - 1] + b[r + 1] + max(dp[1], dp[2]));
      if (l == 2) {
        int tr = 1;
      }
    }
  }
  cout << ans << endl;
}
