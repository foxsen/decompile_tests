#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int bit[2005];
  void init() { memset(bit, 0, sizeof(bit)); }
  void add(int k, int x) {
    k++;
    while (k < 2005) {
      bit[k] += x;
      k += k & -k;
    }
  }
  int get(int k) {
    k++;
    int ret = 0;
    while (k > 0) {
      ret += bit[k];
      k -= k & -k;
    }
    return ret;
  }
  int get(int s, int t) { return get(t) - get(s - 1); }
};
BIT bit1, bit2;
long long int dp[2005][2005];
long long int rt[2005];
int A[2005][2005];
bool ux[2005], vy[2005];
int cnt[2005];
void make() {
  for (int i = 0; i < 2005; i++) {
    if (i == 0)
      dp[i][0] = 1;
    else if (i == 1)
      dp[i][0] = 0;
    else if (i == 2)
      dp[i][0] = 1;
    else
      dp[i][0] =
          (long long int)(i - 1) * (dp[i - 1][0] + dp[i - 2][0]) % 998244353;
    for (int j = 1; j < 2005; j++) {
      dp[i][j] = ((i == 0 ? 0 : dp[i - 1][j]) * (long long int)i +
                  dp[i][j - 1] * (long long int)j) %
                 998244353;
    }
  }
}
void insX(int v) {
  ux[v] = true;
  if (vy[v])
    bit1.add(v, -1);
  else
    bit2.add(v, -1);
}
void rmY(int v) {
  vy[v] = false;
  if (!ux[v]) {
    bit1.add(v, -1);
    bit2.add(v, 1);
  }
}
int main() {
  make();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &A[i][j]), A[i][j]--;
  rt[0] = 1;
  for (int i = 1; i < 2005; i++) rt[i] = rt[i - 1] * dp[n][0] % 998244353;
  long long int ret = 0;
  for (int i = 0; i < n; i++) {
    bit1.init();
    bit2.init();
    for (int j = 0; j < n; j++) ux[j] = vy[j] = false;
    if (i > 0) {
      for (int j = 0; j < n; j++) vy[j] = true, bit1.add(j, 1);
    } else {
      for (int j = 0; j < n; j++) bit2.add(j, 1);
    }
    for (int j = 0; j < n; j++) {
      if (i > 0) {
        rmY(A[i - 1][j]);
      }
      if (A[i][j] > 0) {
        int a = bit1.get(0, n);
        int b = bit2.get(0, n);
        int c = bit1.get(0, A[i][j] - 1);
        int d = bit2.get(0, A[i][j] - 1);
        if (i > 0 && A[i - 1][j] < A[i][j] && !ux[A[i - 1][j]]) d--;
        if (a > 0)
          ret += (long long int)c * (long long int)dp[a - 1][b] % 998244353 *
                 rt[n - i - 1] % 998244353;
        if (b > 0)
          ret += (long long int)d * (long long int)dp[a][b - 1] % 998244353 *
                 rt[n - i - 1] % 998244353;
        ret %= 998244353;
      }
      insX(A[i][j]);
    }
  }
  printf("%lld\n", ret);
  return 0;
}
