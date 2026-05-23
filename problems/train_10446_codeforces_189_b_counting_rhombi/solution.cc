#include <bits/stdc++.h>
using namespace std;
void FastInputOutput() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline int D() {
  int t;
  scanf("%d", &t);
  return t;
}
inline long long LLD() {
  long long t;
  scanf("%lld", &t);
  return t;
}
long long power(long long x, long long p, long long m) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
long double ModLog(long double base, long double x) {
  return (logl(x) / logl(base));
}
const int N = 2e6 + 5, MX = 1e9;
int mod(int a, int m) { return (((a % m) + m) % m); }
int main() {
  int n = D(), m = D();
  long long sum = 0;
  for (long long i = 1; i <= n / 2; ++i)
    for (long long j = 1; j <= m / 2; ++j)
      sum += (n - i * 2 + 1) * (m - j * 2 + 1);
  printf("%lld", sum);
  return 0;
}
