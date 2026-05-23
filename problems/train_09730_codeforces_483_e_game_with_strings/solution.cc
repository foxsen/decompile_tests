#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, vis[(1 << 21) + 1], col = 1, m, tw[22], cnt[(1 << 21) + 1];
long long dp[(1 << 21) + 1];
string st[55];
long long rep[(1 << 21) + 1];
int count_bit(long long x) {
  int ret = 0;
  while (x) {
    ret++;
    x ^= x & (-x);
  }
  return ret;
}
int main() {
  cin >> n;
  if (n == 1) {
    printf("%.10lf\n", 0.);
    return 0;
  }
  for (int i = 0; i < 22; i++) tw[i] = 1 << i;
  for (int i = 0; i < n; i++) cin >> st[i];
  m = st[0].size();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) {
        int msk = 0;
        for (int z = 0; z < m; z++)
          if (st[i][z] == st[j][z]) msk |= tw[z];
        rep[msk] |= 1ll << i;
      }
  for (int msk = tw[m] - 1; msk >= 0; msk--)
    for (int i = 0; i < m; i++)
      if (msk & tw[i]) {
        rep[msk ^ tw[i]] |= rep[msk];
      }
  for (int msk = tw[m + 1] - 1; msk >= 0; msk--) cnt[msk] = count_bit(msk);
  for (int msk = 0; msk < tw[m]; msk++) {
    int c = cnt[msk];
    for (int i = 0; i < m; i++)
      if (!(msk & tw[i])) {
        long long tmp = rep[msk] ^ rep[msk ^ tw[i]];
        dp[c + 1] += count_bit(tmp);
      }
  }
  double ans = 0;
  for (int i = 1; i < m + 1; i++) {
    double tmp = double(dp[i] * i) / (m - i + 1);
    for (int j = 0; j < i - 1; j++) tmp *= double(i - 1 - j) / (m - j);
    ans += tmp;
  }
  ans /= n;
  printf("%.10lf\n", ans);
  return 0;
}
