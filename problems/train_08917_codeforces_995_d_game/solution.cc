#include <bits/stdc++.h>
using namespace std;
double a[1000010], x, ans;
int main() {
  int N, R, W, i, j;
  scanf("%d%d", &N, &R);
  W = 1 << N;
  for (i = 0; i < W; i++) scanf("%lf", &a[i]), ans += a[i];
  printf("%.10lf\n", ans / W);
  for (i = 1; i <= R; i++) {
    scanf("%d%lf", &j, &x);
    ans -= a[j];
    a[j] = x;
    ans += a[j];
    printf("%.10lf\n", ans / W);
  }
  return 0;
}
