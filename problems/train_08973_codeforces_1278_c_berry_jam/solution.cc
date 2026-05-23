#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn * 2];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int red = 0, blue = 0;
    map<int, int> m;
    for (int i = 1; i <= n * 2; i++) {
      int color;
      scanf("%d", &color);
      if (color == 1) {
        red++;
        a[i] = 1;
      } else {
        blue++;
        a[i] = -1;
      }
    }
    if (red == blue) {
      puts("0");
      continue;
    }
    m[0] = n;
    m[a[n + 1]] = n + 1;
    for (int i = n + 2; i <= n * 2; i++) {
      a[i] += a[i - 1];
      if (!m.count(a[i])) {
        m[a[i]] = i;
      }
    }
    int lsum = 0;
    int diff = red - blue;
    int ans = n * 2;
    if (m.count(diff)) {
      ans = min(ans, m[diff] - n);
    }
    for (int i = n; i; i--) {
      lsum += a[i];
      if (m.count(diff - lsum)) {
        int r = m[diff - lsum];
        ans = min(ans, r - i + 1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
