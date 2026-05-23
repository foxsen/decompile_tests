#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const int inf = (1 << 31) - 1;
const int hinf = 1000000000;
const int mod = 1000000007;
int main() {
  double e = 1;
  int n;
  cin >> n;
  double p;
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p);
    ans += e * p;
    e = 1 + (1 + e) * p;
  }
  printf("%.15lf\n", ans);
}
