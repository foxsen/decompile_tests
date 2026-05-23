#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
int n, m;
int bl;
int a[100005], nex[100005], steps[100005], b[100005];
int main() {
  scanf("%d%d", &n, &m);
  bl = sqrt(n);
  for (int i = 0; i < (n); i++) scanf("%d", &a[i]), b[i] = i / bl;
  for (int i = (n - 1); i >= 0; i--) {
    int x = i + a[i];
    if (x >= n)
      nex[i] = -1, steps[i] = 1;
    else if (b[i] == b[x])
      nex[i] = nex[x], steps[i] = 1 + steps[x];
    else
      nex[i] = x, steps[i] = 1;
  }
  while (m--) {
    int type, x, y, z;
    scanf("%d", &type);
    if (type == 0) {
      scanf("%d%d", &x, &y);
      x--;
      a[x] = y;
      if (x + y >= n)
        nex[x] = -1, steps[x] = 1;
      else if (b[x] == b[x + y])
        nex[x] = nex[x + y], steps[x] = 1 + steps[x + y];
      else
        nex[x] = x + y, steps[x] = 1;
      while (x > 0 and b[x] == b[x - 1]) {
        x--;
        y = a[x];
        if (x + y >= n)
          nex[x] = -1, steps[x] = 1;
        else if (b[x] == b[x + y])
          nex[x] = nex[x + y], steps[x] = 1 + steps[x + y];
        else
          nex[x] = x + y, steps[x] = 1;
      }
    } else {
      scanf("%d", &x);
      x--;
      int ans = 0, cur = x;
      while (x != -1) {
        ans += steps[x];
        cur = x;
        x = nex[x];
      }
      while (cur < n) x = cur, cur = cur + a[cur];
      printf("%d %d\n", x + 1, ans);
    }
  }
}
