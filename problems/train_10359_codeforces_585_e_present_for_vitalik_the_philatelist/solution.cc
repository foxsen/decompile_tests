#include <bits/stdc++.h>
using namespace std;
const int N = 500100, mod = 1e9 + 7, M = 10000001;
int f[N], p[M], tot, c[M], mu[M], a[N], b[N][20], bn[N];
bool is[M];
int cal(int x) { return f[x] - 1; }
void add(int &x, int y) {
  if (y < 0) y += mod;
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = f[i - 1] * 2 % mod;
  mu[1] = 1;
  for (int i = 2; i < M; i++) {
    if (!is[i]) {
      p[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * p[j] < M; j++) {
      is[i * p[j]] = 1;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = -mu[i];
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int tmp = a[i];
    bn[i] = 0;
    for (int j = 0; p[j] * p[j] <= tmp; j++)
      if (tmp % p[j] == 0) {
        while (tmp % p[j] == 0) tmp /= p[j];
        b[i][bn[i]++] = p[j];
      }
    if (tmp != 1) b[i][bn[i]++] = tmp;
    for (int j = 1; j < (1 << bn[i]); j++) {
      int tmp = 1;
      for (int k = 0; k < bn[i]; k++)
        if (j & (1 << k)) {
          tmp *= b[i][k];
        }
      c[tmp]++;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    add(res, cal(n - 1));
    for (int j = 1; j < (1 << bn[i]); j++) {
      int tmp = 1;
      for (int k = 0; k < bn[i]; k++)
        if (j & (1 << k)) {
          tmp *= b[i][k];
        }
      add(res, mu[tmp] * cal(c[tmp] - 1));
    }
  }
  add(res, -1LL * n * cal(n - 1) % mod);
  for (int i = 2; i < M; i++)
    if (c[i]) {
      add(res, -mu[i] *
                   (1LL * c[i] * cal(c[i] - 1) + 1LL * (n - c[i]) * cal(c[i])) %
                   mod);
    }
  cout << res << endl;
}
