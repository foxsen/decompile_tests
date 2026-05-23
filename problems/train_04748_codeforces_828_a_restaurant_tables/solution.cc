#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, ans = 0, t;
  string s;
  cin >> n >> a >> b;
  int x, y, z;
  x = a, y = b, z = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t == 1) {
      if (x > 0) {
        x--;
      } else if (y > 0) {
        y--, z++;
      } else if (z > 0)
        z--;
      else
        ans++;
    } else {
      if (y > 0)
        y--;
      else
        ans += 2;
    }
  }
  cout << ans;
  return 0;
}
