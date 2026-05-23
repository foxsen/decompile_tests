#include <bits/stdc++.h>
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
bool valid(int r, int c, int x, int y) {
  if (x >= 1 && x <= r && y >= 1 && y <= c) return 1;
  return 0;
}
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 2];
  int b[n + 2];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  int ans = 0, cnt = 1;
  while (true) {
    if (cnt == (n + 1)) {
      cnt = 1;
      ans++;
    }
    if (a[cnt] <= b[cnt])
      b[cnt] -= a[cnt];
    else {
      if (k < (a[cnt] - b[cnt])) {
        break;
      } else {
        k -= (a[cnt] - b[cnt]);
        b[cnt] = 0;
      }
    }
    cnt++;
  }
  cout << ans << endl;
  return 0;
}
