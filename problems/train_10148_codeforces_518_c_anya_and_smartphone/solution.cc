#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  return (!a) ? b : (!b) ? a : gcd(b, a % b);
}
int main() {
  long long i, arr[100005], j, k, n, m, ord[100005];
  map<long long, long long> mape;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &k);
  for (i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    mape[arr[i]] = i;
  }
  long long moves = 0, x, y, xx, yy, h;
  for (i = 0; i < m; i++) {
    scanf("%lld", &h);
    moves += (mape[h] / k) + 1;
    if (mape[h] >= 1) {
      x = mape[h];
      y = x - 1;
      xx = arr[x];
      yy = arr[y];
      arr[x] = yy;
      arr[x - 1] = xx;
      mape[xx] = y;
      mape[yy] = x;
    }
  }
  printf("%lld", moves);
  printf("\n");
  return 0;
}
