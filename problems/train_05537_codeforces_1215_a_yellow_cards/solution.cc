#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int a1, a2, k1, k2, ans1, ans2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int x = n - (k1 - 1) * a1 - (k2 - 1) * a2;
  if (x <= 0)
    ans1 = 0;
  else
    ans1 = x;
  if (k1 <= k2) {
    ans2 = n / k1;
    if (ans2 > a1) {
      ans2 = a1;
      ans2 += (n - a1 * k1) / k2;
    }
  }
  if (k1 > k2) {
    ans2 = n / k2;
    if (ans2 > a2) {
      ans2 = a2;
      ans2 += (n - a2 * k2) / k1;
    }
  }
  if (ans1 > a1 + a2) ans1 = a1 + a2;
  if (ans2 > a1 + a2) ans2 = a1 + a2;
  cout << ans1 << " " << ans2 << endl;
}
