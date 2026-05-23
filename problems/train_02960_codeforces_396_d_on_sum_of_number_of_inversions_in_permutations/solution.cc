#include <bits/stdc++.h>
using namespace std;
long long f[1000005], b[1000005], bit[1000005], _n, _len;
void update(long long i, long long val) {
  while (i <= _n) {
    bit[i] += val;
    i += (i & (-i));
  }
}
long long query(long long i) {
  long long sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= (i & (-i));
  }
  return sum;
}
int main() {
  long long i, j, k, p, q, m, n, c, sm;
  while (cin >> n) {
    for (_n = n, f[0] = 1, b[0] = 0, i = 1; i <= n; i++) {
      update(i, 1);
      f[i] = (f[i - 1] * i) % 1000000007LL;
      b[i] = ((b[i - 1] * i) % 1000000007LL +
              (((i * (i - 1)) / 2) % 1000000007LL * f[i - 1]) % 1000000007LL) %
             1000000007LL;
    }
    for (sm = 0, p = 0, i = 1, j = n - 1; i <= n; i++, j--) {
      cin >> q;
      k = query(q - 1);
      sm = (sm + k * b[j] + (k * (k - 1) / 2 + p * k) % 1000000007LL * f[j]) %
           1000000007LL;
      p = (p + k) % 1000000007LL;
      update(q, -1);
    }
    cout << (sm + p) % 1000000007LL << endl;
  }
  return 0;
}
