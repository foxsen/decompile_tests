#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N];
int main(int argc, const char* argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    if (x < 0 && y > 0)
      printf("%lld\n", (1ll * abs(x) + abs(y)) * a);
    else if (x > 0 && y < 0)
      printf("%lld\n", (1ll * abs(x) + abs(y)) * a);
    else {
      x = abs(x);
      y = abs(y);
      long long mx = max(x, y), mn = min(x, y);
      printf("%lld\n", (mx - mn) * a + mn * min(b, 2 * a));
    }
  }
}
