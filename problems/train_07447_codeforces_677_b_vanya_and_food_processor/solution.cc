#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, k;
  vector<int> p;
  scanf("%d %d %d", &n, &h, &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    p.push_back(x);
  }
  long long g = 0, c = 0;
  long long resp = 0;
  while (1) {
    while (g + p[c] <= h && c < p.size()) {
      g += p[c++];
    }
    if (c < p.size()) {
      long long x = p[c] - (h - g);
      long long y = x / k + (x % k > 0);
      resp += y;
      g = max(g - y * k, 0LL);
    } else
      break;
  }
  resp += g / k + (g % k > 0);
  printf("%lld\n", resp);
  return 0;
}
