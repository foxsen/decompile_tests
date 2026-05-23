#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 11;
int a[N];
void run() {
  for (int i = (0); i < (N); ++i) scanf("%d", &a[i]);
  for (int i = N - 1; i >= 0; --i) {
    double res = sqrt(abs(a[i])) + 5 * pow(a[i], 3);
    if (res <= 400)
      printf("f(%d) = %.2lf\n", a[i], res);
    else
      printf("f(%d) = MAGNA NIMIS!\n", a[i]);
  }
}
int main() {
  run();
  return 0;
}
