#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXHOLE = 5000;
const int MAXMOUSE = 5000;
const int MAXLG = 12;
int nmouse, nhole;
int cnt[MAXHOLE];
int hole[MAXHOLE];
int mouse[MAXMOUSE];
long long mousesum[MAXMOUSE + 1];
int fst[MAXHOLE];
long long dp[MAXHOLE + 1][MAXMOUSE + 1];
long long v[MAXMOUSE + 1];
int q[MAXMOUSE + 1], qhead, qtail;
long long myadd(long long a, long long b) {
  return a == LLONG_MAX || b == LLONG_MAX ? LLONG_MAX : a + b;
}
pair<int, int> o[MAXHOLE];
void run() {
  scanf("%d%d", &nmouse, &nhole);
  for (int i = (0); i < (nmouse); ++i) scanf("%d", &mouse[i]);
  for (int i = (0); i < (nhole); ++i) scanf("%d%d", &o[i].first, &o[i].second);
  sort(mouse, mouse + nmouse);
  sort(o, o + nhole);
  for (int i = (0); i < (nhole); ++i)
    hole[i] = o[i].first, cnt[i] = o[i].second;
  mousesum[0] = 0;
  for (int i = (0); i < (nmouse); ++i) mousesum[i + 1] = mousesum[i] + mouse[i];
  for (int i = nhole - 1; i >= 0; --i) {
    fst[i] = i == nhole - 1 ? nmouse : fst[i + 1];
    while (fst[i] - 1 >= 0 && mouse[fst[i] - 1] >= hole[i]) --fst[i];
  }
  for (int j = (0); j <= (nmouse); ++j) dp[0][j] = j == 0 ? 0 : LLONG_MAX;
  for (int i = (0); i < (nhole); ++i) {
    for (int j = (0); j <= (nmouse); ++j) dp[i + 1][j] = LLONG_MAX;
    for (int k = (0); k <= (nmouse); ++k)
      v[k] = myadd(dp[i][k], (long long)+k * hole[i] - mousesum[k]);
    qhead = qtail = 0;
    for (int j = (0); j <= (nmouse); ++j) {
      while (qtail < qhead && v[q[qhead - 1]] >= v[j]) --qhead;
      q[qhead++] = j;
      int kmn = max(max(0, j - cnt[i]), fst[i]);
      while (qtail < qhead && q[qtail] < kmn) ++qtail;
      if (fst[i] <= j && qtail < qhead) {
        long long cur =
            myadd(v[q[qtail]], mousesum[j] - (long long)j * hole[i]);
        if (cur < dp[i + 1][j]) dp[i + 1][j] = cur;
      }
    }
    for (int k = (0); k <= (nmouse); ++k)
      v[k] = myadd(dp[i][k], (long long)-k * hole[i] + mousesum[k]);
    qhead = qtail = 0;
    for (int j = (0); j <= (nmouse); ++j) {
      if (j < fst[i]) {
        while (qtail < qhead && v[q[qhead - 1]] >= v[j]) --qhead;
        q[qhead++] = j;
      }
      int kmn = max(0, j - cnt[i]);
      while (qtail < qhead && q[qtail] < kmn) ++qtail;
      if (kmn < fst[i] && fst[i] <= j) {
        long long cur =
            myadd(v[q[qtail]], (long long)fst[i] * hole[i] - mousesum[fst[i]] +
                                   mousesum[j] - mousesum[fst[i]] -
                                   (long long)(j - fst[i]) * hole[i]);
        if (cur < dp[i + 1][j]) dp[i + 1][j] = cur;
      }
      if (j < fst[i]) {
        long long cur =
            myadd(v[q[qtail]], (long long)j * hole[i] - mousesum[j]);
        if (cur < dp[i + 1][j]) dp[i + 1][j] = cur;
      }
    }
  }
  long long ret = dp[nhole][nmouse];
  printf("%lld\n", ret == LLONG_MAX ? -1 : ret);
}
int main() {
  run();
  return 0;
}
