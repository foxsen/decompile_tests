#include <bits/stdc++.h>
using namespace std;
const long long INF = 999999999999999999;
const double PI = acos(-1.0);
void stop() { exit(0); }
int main() {
  double n, r;
  cin >> n >> r;
  double sn = sin(PI / n);
  double x = (2.0 * r * sn) / (2.0 - 2.0 * sn);
  printf("%.9lf", x);
  stop();
}
