#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int x[N], y[N], z[N];
double sqr(double x) { return x * x; }
double dis(int i, int j) {
  return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", x + i, y + i, z + i);
  }
  double mn = 1e18;
  for (int i = 2; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      mn = min(mn, dis(1, i) + dis(i, j) + dis(1, j));
    }
  }
  printf("%.10f\n", mn / 2);
  return 0;
}
