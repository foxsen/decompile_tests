#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
template <class T>
inline T read() {
  T x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m;
long long a[100010], c[100010 + 101][101], s[105][100010];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int main() {
  n = read<int>(), m = read<int>();
  for (int i = 1; i <= n; i++) {
    a[i] = read<long long>() % mod;
  }
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
  }
  for (int i = 1; i <= n + 100; i++) {
    for (int j = 1; j <= 100; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j] + mod) % mod;
    }
  }
  for (int i = 1; i <= m; i++) {
    int l = read<int>(), r = read<int>(), k = read<int>();
    s[k + 1][l]++;
    s[k + 1][l] %= mod;
    for (int j = 1; j <= k + 1; j++) {
      s[j][r + 1] -= c[k + 1 - j + r - l][k + 1 - j];
      s[j][r + 1] += mod;
      s[j][r + 1] %= mod;
    }
  }
  for (int k = 100; k >= 0; k--) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += s[k + 1][i];
      cnt %= mod;
      s[k][i] += cnt;
      s[k][i] %= mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = (a[i] + s[0][i]) % mod;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
