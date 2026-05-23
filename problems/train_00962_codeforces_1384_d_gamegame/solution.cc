#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
int t, n, x;
int num[30];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) {
      cin >> x;
      int cnt = 0;
      while (x) {
        if (x & 1) {
          num[cnt]++;
        }
        x >>= 1;
        cnt++;
      }
    }
    for (int i = 29; i >= 0; i--) {
      if (num[i] & 1) {
        if (!((n - num[i]) & 1) && (num[i] % 4 == 3)) {
          cout << "LOSE" << '\n';
        } else {
          cout << "WIN" << '\n';
        }
        goto end;
      }
    }
    cout << "DRAW" << '\n';
  end:;
  }
  return 0;
}
