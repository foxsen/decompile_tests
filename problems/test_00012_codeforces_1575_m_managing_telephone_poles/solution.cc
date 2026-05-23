#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, mp[N][N], pre[N], qu[N], head, tail;
long long dp[N][N];
char ch[N];
long double slope(int fi, int se, int id) {
  long double X1 = 2 * fi, Y1 = fi * fi + (id - pre[fi]) * (id - pre[fi]);
  long double X2 = 2 * se, Y2 = se * se + (id - pre[se]) * (id - pre[se]);
  return (Y1 - Y2) / (X1 - X2);
}
void work() {
  for (int j = 1; j <= m; j++) pre[j] = -2 * n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (mp[i][j]) pre[j] = i;
    tail = 0, head = 1;
    for (int j = 1; j <= m; j++) {
      while (2 <= tail &&
             slope(qu[tail - 1], qu[tail], i) > slope(qu[tail], j, i))
        tail--;
      qu[++tail] = j;
    }
    if (head > tail) continue;
    for (int j = 1; j <= m; j++) {
      while (head + 1 <= tail && slope(qu[head], qu[head + 1], i) < j) head++;
      int nw = qu[head];
      dp[i][j] = min(dp[i][j], 1ll * (j - nw) * (j - nw) +
                                   1ll * (i - pre[nw]) * (i - pre[nw]));
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  n++;
  m++;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= m; j++) mp[i][j] = ch[j] - '0';
  }
  work();
  for (int i = 1; i <= (n / 2); i++)
    swap(mp[i], mp[n - i + 1]), swap(dp[i], dp[n - i + 1]);
  work();
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans += dp[i][j];
  printf("%lld\n", ans);
  return 0;
}
