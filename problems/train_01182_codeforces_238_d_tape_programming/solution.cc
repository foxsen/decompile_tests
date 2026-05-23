#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
char s[110], tmp[110];
bool vis[110];
int num[110];
void doit() {
  int dp = 1, cp = l, tp;
  while (cp >= l && cp <= r) {
    if (tmp[cp] == '<' || tmp[cp] == '>') {
      if (tmp[cp] == '<') {
        dp = -1;
        tp = cp - 1;
        while (tp >= l && vis[tp]) tp--;
        if (tp < l) break;
        if (tmp[tp] == '<' || tmp[tp] == '>') vis[cp] = true;
        cp = tp;
        continue;
      } else {
        dp = 1;
        tp = cp + 1;
        while (tp <= r && vis[tp]) tp++;
        if (tp > r) break;
        if (tmp[tp] == '<' || tmp[tp] == '>') vis[cp] = true;
        cp = tp;
        continue;
      }
    } else {
      if (tmp[cp] == '0') {
        num[0]++;
        vis[cp] = true;
        cp += dp;
        while (cp >= l && cp <= r && vis[cp]) cp += dp;
      } else {
        num[tmp[cp] - '0']++;
        tmp[cp]--;
        cp += dp;
        while (cp >= l && cp <= r && vis[cp]) cp += dp;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  while (q--) {
    scanf("%d%d", &l, &r);
    memset(num, 0, sizeof(num));
    memcpy(tmp, s, sizeof(s));
    memset(vis, 0, sizeof(vis));
    doit();
    for (int i = 0; i < 9; i++) printf("%d ", num[i]);
    printf("%d\n", num[9]);
  }
  return 0;
}
