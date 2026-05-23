#include <bits/stdc++.h>
using namespace std;
int n;
double p[110];
double mval = -1.0;
inline int iabs(int x) { return x < 0 ? -x : x; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 0; i <= n; i++) {
    int a = n - 2 * i;
    if (a <= 0) break;
    for (int j = n; j >= 0; j--) {
      int b = n - 2 * j;
      if (b >= 0) break;
      if (!a && !b) continue;
      double val = (p[i] * double(iabs(b)) + p[j] * double(iabs(a))) /
                   double(iabs(a) + iabs(b));
      mval = max(mval, val);
    }
  }
  if (n % 2 == 0) {
    mval = max(mval, p[n / 2]);
  }
  printf("%.9lf", mval);
  return 0;
}
