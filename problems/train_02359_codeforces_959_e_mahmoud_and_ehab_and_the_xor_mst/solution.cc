#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
long long n;
long long solve(long long n, long long k) {
  if (n == 1) return 0;
  return solve(n - n / 2, k << 1) + (n / 2) * k;
}
signed main() {
  read(n);
  printf("%lld\n", solve(n, 1));
  return 0;
}
