#include <bits/stdc++.h>
using namespace std;
long long a[] = {1,       2,       3,       5,       7,        13,      17,
                 19,      31,      61,      89,      107,      127,     521,
                 607,     1279,    2203,    2281,    3217,     4253,    4423,
                 9689,    9941,    11213,   19937,   21701,    23209,   44497,
                 86243,   110503,  132049,  216091,  756839,   859433,  1257787,
                 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};
long long quickpow(long long m, long long n) {
  long long ans = 1;
  long long k = 1000000007;
  while (n) {
    if (n & 1) ans = (ans * m) % k;
    n = n >> 1;
    m = (m * m) % k;
  }
  return ans;
}
int main() {
  long long n;
  cin >> n;
  cout << quickpow(2, a[n] - 1) - 1 << "\n";
  return 0;
}
