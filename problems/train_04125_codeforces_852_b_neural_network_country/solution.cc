#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int a[101][101], b[101][101], w[101], m, d[101], first[101], second[1000010];
long long c[101][101];
void mul(int a[101][101], int b[101][101]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = 0;
      for (int k = 0; k < m; k++) {
        c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j] % 1000000007);
      }
    }
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) a[i][j] = c[i][j] % 1000000007;
}
int main() {
  int j, k, i, T, ca = 0, n, K = 0;
  scanf("%d%d%d", &n, &K, &m);
  for (int i = 0; i < n; i++) scanf("%d", &k), k %= m, first[k]++;
  for (int i = 0; i < n; i++) scanf("%d", &k), k %= m, w[k]++, second[i] = k;
  for (int i = 0; i < n; i++) scanf("%d", &k), second[i] += k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      k = (j - i + m) % m;
      a[i][j] = w[k];
    }
  }
  for (int i = 0; i < m; i++) b[i][i] = 1;
  K -= 2;
  while (K) {
    if (K & 1) mul(b, a);
    mul(a, a);
    K >>= 1;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++)
    if (first[i]) {
      for (int j = 0; j < m; j++) {
        int v = 1LL * first[i] * b[i][j] % 1000000007;
        add(d[j], v);
      }
    }
  for (int i = 0; i < n; i++) {
    j = second[i] % m;
    j = m - j;
    if (j == m) j = 0;
    ans += d[j];
  }
  ans %= 1000000007;
  printf("%d\n", (int)ans);
  return 0;
}
