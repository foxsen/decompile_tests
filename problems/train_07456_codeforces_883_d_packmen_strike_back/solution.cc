#include <bits/stdc++.h>
const int N = 1000000;
int n;
char str[N + 10];
int cdog = 0, fdog = 0, ldog = 0, cbone = 0, fbone = 0, lbone = 0;
int cntd[N + 10], cntb[N + 10];
int nxtd[N + 10], nxtb[N + 10];
int lstd[N + 10], lstb[N + 10];
int tp1[N + 10], tp2[N + 10][2];
bool dp[N + 10];
bool chk(int x) {
  memset(dp, 0, sizeof(dp));
  dp[0] = true;
  for (int i = n; i >= 0; --i) {
    if (str[i] != 'P') continue;
    int nd = lstd[std::min(i + x, n)];
    if (nd > i)
      tp1[i] = tp1[nd];
    else
      tp1[i] = i + x;
  }
  for (int i = n; i >= 0; --i) {
    if (str[i] != 'P') continue;
    int nd = lstd[std::min(i + x, n)], bd = nxtd[i + 1];
    if (!bd)
      tp2[i][0] = n + 1, tp2[i][1] = 0;
    else if (nd == bd)
      tp2[i][0] = bd - x, tp2[i][1] = i + x;
    else
      tp2[i][0] = bd - x, tp2[i][1] = tp1[nd];
  }
  for (int i = 0; i < n; ++i) {
    if (!dp[i]) continue;
    int nd = nxtd[i + 1];
    int nb = nxtb[i + 1];
    if (nd == 0 || nb == 0) break;
    if (nb < nd) {
      if (nb >= nd - x) {
        dp[nd] = true;
      }
      if (nb >= tp2[nd][0]) {
        dp[std::min(tp2[nd][1], n)] = true;
      }
    } else {
      dp[std::min(tp1[nd], n)] = true;
    }
  }
  int lst = 0;
  for (int i = n; i >= 0; --i)
    if (dp[i]) {
      lst = i;
      break;
    }
  return lst >= lbone;
}
int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++i)
    if (str[i] == 'P') {
      ++cdog;
      if (fdog == 0) fdog = i;
      ldog = i;
      cntd[i] = cntd[i - 1] + 1;
      cntb[i] = cntb[i - 1];
    } else if (str[i] == '*') {
      ++cbone;
      if (fbone == 0) fbone = i;
      lbone = i;
      cntd[i] = cntd[i - 1];
      cntb[i] = cntb[i - 1] + 1;
    } else {
      cntd[i] = cntd[i - 1];
      cntb[i] = cntb[i - 1];
    }
  if (cdog == 1) {
    if (cntb[ldog] > cbone - cntb[ldog]) {
      printf("%d %d\n", cntb[ldog], ldog - fbone);
    } else {
      printf("%d %d\n", cbone - cntb[ldog], lbone - ldog);
    }
    return 0;
  }
  printf("%d ", cbone);
  for (int i = n; i >= 0; --i) {
    if (str[i] == 'P')
      nxtd[i] = i;
    else
      nxtd[i] = nxtd[i + 1];
    if (str[i] == '*')
      nxtb[i] = i;
    else
      nxtb[i] = nxtb[i + 1];
  }
  for (int i = 1; i <= n; ++i) {
    if (str[i] == 'P')
      lstd[i] = i;
    else
      lstd[i] = lstd[i - 1];
    if (str[i] == '*')
      lstb[i] = i;
    else
      lstb[i] = lstb[i - 1];
  }
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (chk(mid)) {
      ans = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
