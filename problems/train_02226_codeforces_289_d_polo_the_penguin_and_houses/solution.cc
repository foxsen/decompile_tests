#include <bits/stdc++.h>
using namespace std;
const int maxn = 1020;
const int maxx = 10000;
const int MOd = 1e9 + 7;
const int K = 750;
int n, k;
int dn[maxn][maxn];
int mul(int a, int b) { return (long long)a * b % MOd; }
int main() {
  scanf("%d %d", &n, &k);
  int t = k;
  for (int i = 1; i <= n - k; i++) t = mul(t, n - k);
  int ans = 0;
  k--;
  for (int i = 0; i < (1 << k); i++) dn[(1 << k) - 1][i] = 1;
  for (int i = (1 << k) - 2; i >= 0; i--) {
    for (int j = (1 << k) - 2; j >= 0; j--)
      if ((i | j) == i) {
        int h = ((1 << k) - 1) ^ i;
        for (int k = h; k; k = (k - 1) & h) {
          int l = k;
          int x = __builtin_popcount(k);
          int y = __builtin_popcount(j);
          int p = 1;
          while (y--) p = mul(p, x);
          p %= MOd;
          dn[i][j] += mul(dn[i | k][k], p);
          dn[i][j] %= MOd;
        }
      }
  }
  ans = mul(t, dn[0][0]);
  cout << ans << endl;
  return 0;
}
