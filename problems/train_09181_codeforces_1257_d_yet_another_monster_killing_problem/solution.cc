#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int inf = 0x3f3f3f3f;
int p[200005];
int v[200005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int a = 1; a <= n; a++) {
      scanf("%d", &v[a]);
      p[a] = 0;
    }
    int m, x, y;
    scanf("%d", &m);
    for (int a = 1; a <= m; a++) {
      scanf("%d%d", &x, &y);
      p[y] = max(p[y], x);
    }
    for (int a = n - 1; a >= 1; a--) {
      p[a] = max(p[a], p[a + 1]);
    }
    int mx = 0, num = 1, flog = 0, ans = 0;
    for (int a = 1; a <= n; a++) {
      mx = max(mx, v[a]);
      if (p[a - ans] < mx) {
        mx = v[a];
        num++;
        ans = a - 1;
      }
      if (p[1] < mx) {
        flog = 1;
        break;
      }
    }
    if (flog) {
      printf("-1\n");
    } else {
      printf("%d\n", num);
    }
  }
  return 0;
}
