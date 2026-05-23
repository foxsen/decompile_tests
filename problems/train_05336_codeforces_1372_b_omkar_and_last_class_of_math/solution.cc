#include <bits/stdc++.h>
const long long iinf = 1e18;
const int inf = 1e9 + 10;
const int MOD = (1e6 + 3);
int dir4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int knight[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = i;
      break;
    }
  }
  if (ans == 1) {
    cout << 1 << " " << n - 1 << "\n";
    return;
  }
  int a = n / ans;
  cout << a << " " << (ans - 1) * a << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
