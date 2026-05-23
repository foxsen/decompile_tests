#include <bits/stdc++.h>
using namespace std;
long long pref[2000005];
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long mini = a + b, maxi = b + c, ans = 0;
  memset(pref, (0), sizeof(pref));
  for (int i = a; i <= b; i++) {
    pref[i + b]++;
    pref[i + c + 1]--;
  }
  for (int i = 1; i < 2000005; i++) {
    pref[i] = pref[i] + pref[i - 1];
    if (i > c) {
      ans += pref[i] * (min(i - c, d - c + 1));
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
