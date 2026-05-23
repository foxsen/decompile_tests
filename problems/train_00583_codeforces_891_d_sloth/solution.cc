#include <bits/stdc++.h>
int s[500001], su[500001], ru[500001], ss1[500001], ss2[500001], m, fir[500001],
    nex[1000001], sto[1000001], fa[500001], a1, b1, tot;
long long n, sum, dp[500001][2][2], f[500001][2][2], s1, s2, s3, s4,
    siz[500001], f1[2][2], ans;
bool p[500001][2];
void addbian(int aa, int bb) {
  tot++;
  nex[tot] = fir[aa];
  fir[aa] = tot;
  sto[tot] = bb;
}
void dfs(int x) {
  int aa = fir[x];
  siz[x] = 1;
  dp[x][0][0] = 1;
  while (aa != 0) {
    if (fa[x] != sto[aa]) {
      fa[sto[aa]] = x;
      dfs(sto[aa]);
      siz[x] = siz[x] + siz[sto[aa]];
      s1 = dp[x][0][0];
      s2 = dp[x][0][1];
      s3 = dp[x][1][0];
      s4 = dp[x][1][1];
      if (dp[sto[aa]][1][0] == 0) {
        dp[x][0][0] = 0;
        dp[x][0][1] = 0;
        dp[x][1][0] = 0;
        dp[x][1][1] = 0;
      }
      if (dp[sto[aa]][1][0] > 0)
        ss1[x]++;
      else if (dp[sto[aa]][0][0] > 0)
        ss2[x]++;
      dp[x][0][1] = dp[x][0][1] + s1 * (dp[sto[aa]][0][0] + dp[sto[aa]][1][1]);
      dp[x][1][1] = dp[x][1][1] + s1 * dp[sto[aa]][0][1] +
                    s2 * dp[sto[aa]][0][0] +
                    s3 * (dp[sto[aa]][1][1] + dp[sto[aa]][0][0]);
      if ((s1 > 0) && (dp[sto[aa]][0][0] > 0)) dp[x][1][0] = 1;
    }
    aa = nex[aa];
  }
}
void dfs1(int x) {
  int aa = fir[x];
  s1 = dp[x][0][0];
  s2 = dp[x][0][1];
  s3 = dp[x][1][0];
  s4 = dp[x][1][1];
  if (f[x][1][0] == 0) {
    dp[x][0][0] = 0;
    dp[x][0][1] = 0;
    dp[x][1][0] = 0;
    dp[x][1][1] = 0;
  }
  dp[x][0][1] = dp[x][0][1] + s1 * (f[x][0][0] + f[x][1][1]);
  dp[x][1][1] = dp[x][1][1] + s1 * f[x][0][1] + s2 * f[x][0][0] +
                s3 * (f[x][1][1] + f[x][0][0]);
  if ((s1 > 0) && (f[x][0][0] > 0)) dp[x][1][0] = 1;
  while (aa != 0) {
    if (fa[x] != sto[aa]) {
      if (dp[sto[aa]][1][0] > 0) ss1[x]--;
      if (dp[sto[aa]][0][0] > 0) ss2[x]--;
      if (dp[sto[aa]][1][0] == 0) {
        for (int i = 0; i <= 1; i++)
          for (int j = 0; j <= 1; j++) f1[i][j] = 0;
        if (ss1[x] > ru[x] - 4) {
          f1[0][0] = 1;
          int bb = fir[x];
          while (bb != 0) {
            if ((fa[x] != sto[bb]) && (sto[bb] != sto[aa])) {
              s1 = f1[0][0];
              s2 = f1[0][1];
              s3 = f1[1][0];
              s4 = f1[1][1];
              if (dp[sto[bb]][1][0] == 0) {
                f1[0][0] = 0;
                f1[0][1] = 0;
                f1[1][0] = 0;
                f1[1][1] = 0;
              }
              f1[0][1] =
                  f1[0][1] + s1 * (dp[sto[bb]][0][0] + dp[sto[bb]][1][1]);
              f1[1][1] = f1[1][1] + s1 * dp[sto[bb]][0][1] +
                         s2 * dp[sto[bb]][0][0] +
                         s3 * (dp[sto[bb]][1][1] + dp[sto[bb]][0][0]);
              if ((s1 > 0) && (dp[sto[bb]][0][0] > 0)) f1[1][0] = 1;
            }
            bb = nex[bb];
          }
          s1 = f1[0][0];
          s2 = f1[0][1];
          s3 = f1[1][0];
          s4 = f1[1][1];
          if (f[x][1][0] == 0) {
            f1[0][0] = 0;
            f1[0][1] = 0;
            f1[1][0] = 0;
            f1[1][1] = 0;
          }
          f1[0][1] = f1[0][1] + s1 * (f[x][0][0] + f[x][1][1]);
          f1[1][1] = f1[1][1] + s1 * f[x][0][1] + s2 * f[x][0][0] +
                     s3 * (f[x][1][1] + f[x][0][0]);
          if ((s1 > 0) && (f[x][0][0] > 0)) f1[1][0] = 1;
        }
      } else {
        if (ss1[x] == ru[x] - 1)
          f1[0][0] = 1;
        else
          f1[0][0] = 0;
        if ((ss1[x] == ru[x] - 2) && (ss2[x] == 1))
          f1[1][0] = 1;
        else
          f1[1][0] = 0;
        f1[0][1] =
            dp[x][0][1] - f1[0][0] * (dp[sto[aa]][0][0] + dp[sto[aa]][1][1]);
        f1[1][1] = dp[x][1][1] - f1[0][0] * dp[sto[aa]][0][1] -
                   f1[0][1] * dp[sto[aa]][0][0] +
                   f1[1][0] * (dp[sto[aa]][1][1] + dp[sto[aa]][0][0]);
      }
      if (dp[sto[aa]][1][0] > 0) ss1[x]++;
      if (dp[sto[aa]][0][0] > 0) ss2[x]++;
      if (f1[1][0] > 0)
        ss1[sto[aa]]++;
      else if (f1[0][0] > 0)
        ss2[sto[aa]]++;
      for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) f[sto[aa]][i][j] = f1[i][j];
      if (siz[sto[aa]] % 2 == 0) {
        if ((f1[1][0] > 0) && (dp[sto[aa]][1][0] > 0))
          ans = ans + siz[sto[aa]] * (n - siz[sto[aa]]);
      } else
        ans = ans +
              (f1[0][0] + f1[1][1]) * (dp[sto[aa]][0][0] + dp[sto[aa]][1][1]);
    }
    aa = nex[aa];
  }
  aa = fir[x];
  while (aa != 0) {
    if (sto[aa] != fa[x]) dfs1(sto[aa]);
    aa = nex[aa];
  }
}
int main() {
  scanf("%I64d", &n);
  ans = 0;
  tot = 0;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d", &a1, &b1);
    addbian(a1, b1);
    addbian(b1, a1);
    ru[a1]++;
    ru[b1]++;
  }
  if (n % 2 == 1)
    printf("0");
  else {
    dfs(1);
    f[1][1][0] = 1;
    dfs1(1);
    printf("%I64d\n", ans);
  }
}
