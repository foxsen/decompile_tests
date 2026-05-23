#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5, P = 131, mod = 1e9 + 7;
vector<int> vec, rk[N], dp[N];
vector<unsigned long long> hs[N];
int n, len[N], nxt[N * 10];
char s[N * 10];
unsigned long long bin[N * 10];
inline unsigned long long getHash(int x, int at, int l) {
  if (at > l) return hs[x][l];
  unsigned long long s = at == 0 ? 0 : hs[x][at - 1];
  return s * bin[l + 1 - at] + hs[x][l + 1] - hs[x][at] * bin[l + 1 - at];
}
inline int getChar(int x, int at, int l) {
  if (at > l) return l == 0 ? hs[x][0] : hs[x][l] - hs[x][l - 1] * P;
  return hs[x][l + 1] - hs[x][l] * P;
}
inline int cmp(int x1, int a1, int x2, int a2) {
  int l = -1, r = min(len[x1], len[x2]) - 2, mid;
  while (l < r) {
    if (r == l + 1) break;
    mid = (l + r) >> 1;
    if (getHash(x1, a1, mid) == getHash(x2, a2, mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (getChar(x1, a1, r) < getChar(x2, a2, r)) return 1;
  if (getChar(x1, a1, r) > getChar(x2, a2, r)) return 0;
  int l1 = a1 == len[x1] - 1 ? len[x1] - 1 : len[x1] - 2;
  int l2 = a2 == len[x2] - 1 ? len[x2] - 1 : len[x2] - 2;
  return l1 <= l2;
}
void DP(int x) {
  if (x == 1) {
    for (int i = 0; i < len[1]; i++) dp[1].push_back(1);
    return;
  }
  DP(x - 1);
  int sum = 0, p = -1;
  for (int i = 0; i < len[x]; i++) {
    while (p + 1 < len[x - 1] && cmp(x - 1, rk[x - 1][p + 1], x, rk[x][i])) {
      ++p, sum = (sum + dp[x - 1][p]) % mod;
    }
    dp[x].push_back(sum);
  }
}
int main() {
  bin[0] = 1;
  for (int i = 1; i <= 1000000; i++) bin[i] = bin[i - 1] * P;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s), len[i] = strlen(s), s[len[i]] = '#', ++len[i];
    int l = 0, r;
    while (l < len[i]) {
      r = l;
      while (r + 1 < len[i] && s[r + 1] == s[l]) ++r;
      for (int i = l; i <= r; i++) nxt[i] = r + 1;
      l = r + 1;
    }
    for (int j = 0; j < len[i]; j++) rk[i].push_back(0);
    l = 0, r = len[i] - 1;
    for (int j = 0; j < len[i]; j++) {
      if (l == r) {
        rk[i][l] = j;
      } else if (s[j] < s[nxt[j]]) {
        rk[i][r] = j, --r;
      } else {
        rk[i][l] = j, ++l;
      }
    }
    for (int j = 0; j < len[i]; j++) hs[i].push_back(0);
    hs[i][0] = s[0] - '#';
    for (int j = 1; j < len[i]; j++) hs[i][j] = hs[i][j - 1] * P + s[j] - '#';
  }
  DP(n);
  int ans = 0;
  for (int j = 0; j < len[n]; j++) ans = (ans + dp[n][j]) % mod;
  printf("%d", ans);
  return 0;
}
