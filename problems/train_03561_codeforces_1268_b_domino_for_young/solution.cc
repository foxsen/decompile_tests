#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
int a[maxn];
int main() {
  int n, x, now = 0;
  long long aa = 0, bb = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (now) {
      aa += x / 2;
      bb += x - x / 2;
    } else {
      bb += x / 2;
      aa += x - x / 2;
    }
    now ^= 1;
  }
  printf("%lld\n", min(aa, bb));
  return 0;
}
