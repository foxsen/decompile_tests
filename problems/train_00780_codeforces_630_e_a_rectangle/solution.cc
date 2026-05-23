#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int main() {
  int x1, y1, x2, y2;
  while (~scanf("%d%d%d%d", &x1, &y1, &x2, &y2)) {
    long long x = x2 - x1 + 1;
    long long y = y2 - y1 + 2;
    long long s = x * y / 2 - x / 2;
    printf("%lld\n", s);
  }
}
