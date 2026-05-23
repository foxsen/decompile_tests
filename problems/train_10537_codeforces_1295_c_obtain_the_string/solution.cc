#include <bits/stdc++.h>
int fir[30], f[100010][30];
char s[100010], t[100010];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s + 1, t + 1);
    for (int i = 0; i < 26; ++i) fir[i] = 0;
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for (int i = n; i; --i) {
      for (int j = 0; j < 26; ++j) f[i][j] = fir[j];
      fir[s[i] - 'a'] = i;
    }
    if (!fir[t[1] - 'a']) {
      printf("-1\n");
      continue;
    }
    int ans = 1, now = fir[t[1] - 'a'];
    for (int i = 2; i <= m; ++i) {
      if (f[now][t[i] - 'a'])
        now = f[now][t[i] - 'a'];
      else {
        if (fir[t[i] - 'a'])
          now = fir[t[i] - 'a'], ++ans;
        else {
          ans = -1;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
}
