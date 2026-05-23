#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  int a, h, w;
  scanf("%d %d %d", &a, &h, &w);
  h += a, w += a;
  int g = gcd(h, w);
  int x = h / g, y = w / g;
  int ans = -1;
  for (int i = 1; 1ll * i * i <= g; i++) {
    if (1ll * x * i * a <= h) ans = max(ans, i);
    if (1ll * x * (g / i) * a <= h) ans = max(ans, g / i);
  }
  if (ans == -1 || (ans == 1 && (x == 1 || y == 1))) {
    puts("-1");
    return 0;
  }
  printf("%f\n", 1.0 * h / (x * ans) - a);
}
