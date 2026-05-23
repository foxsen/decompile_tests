#include <bits/stdc++.h>
long long i, j, qa, y, z, t, a, b, c, eqeq, ans, s;
using namespace std;
int main() {
  cin >> a >> b >> c;
  for (i = 2; i <= 8; i++) {
    s = 0;
    qa = a;
    y = b;
    z = c;
    for (j = i; j <= 8; j++) {
      if (j == 2 || j == 5 || j == 8)
        qa--;
      else if (j == 3 || j == 7)
        y--;
      else
        z--;
      if (qa < 0 || y < 0 || z < 0) {
        s = j - i;
        break;
      } else
        s = j - i + 1;
    }
    if (qa < 0 || y < 0 || z < 0) {
      ans = max(ans, s);
      continue;
    }
    eqeq = min(qa / 3, min(y / 2, z / 2));
    qa -= 3 * eqeq;
    y -= 2 * eqeq;
    z -= 2 * eqeq;
    s += eqeq * 7;
    for (j = 2; j <= 8; j++) {
      if (j == 2 || j == 5 || j == 8) {
        qa--;
      } else if (j == 3 || j == 7) {
        y--;
      } else {
        z--;
      }
      if (qa < 0 || y < 0 || z < 0) {
        s += j - 2;
        break;
      }
    }
    ans = max(ans, s);
  }
  cout << ans;
}
