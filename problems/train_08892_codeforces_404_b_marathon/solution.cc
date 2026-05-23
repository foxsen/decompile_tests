#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int px[4] = {0, 1, 1, 0}, py[4] = {0, 0, 1, 1};
int main() {
  int n, t = 0;
  double a, d, now = 0;
  scanf("%lf%lf%d", &a, &d, &n);
  int dt = d / a;
  d -= dt * a;
  for (int i = 0; i < n; i++) {
    now += d;
    if (now > a) {
      now -= a;
      t++;
    }
    t = (t + dt) % 4;
    printf("%.10f %.10f\n", px[t] * a + dx[t] * now, py[t] * a + dy[t] * now);
  }
  return 0;
}
