#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
long long b[100005], dpMax[100005], dpMin[100005], ans = (1ll << 63);
void setup() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
  n--;
}
void xuly() {
  for (int i = n; i >= 1; i--) {
    dpMax[i] = -min(dpMin[i + 1], 0ll) + b[i];
    dpMin[i] = -max(dpMax[i + 1], 0ll) + b[i];
    ans = max(ans, dpMax[i]);
  }
  cout << ans;
}
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  setup();
  xuly();
  return 0;
}
