#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[5], w[5], h[2], score[5] = {500, 1000, 1500, 2000, 2500};
  for (int i = 0; i < 5; i++) cin >> m[i];
  for (int i = 0; i < 5; i++) cin >> w[i];
  cin >> h[0] >> h[1];
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int mx = (3 * score[i]) / 10;
    int cx = (((250 - m[i]) * (score[i] / 250))) - 50 * w[i];
    ans += max(mx, cx);
  }
  ans += 100 * h[0] - 50 * h[1];
  cout << ans << endl;
  return 0;
}
