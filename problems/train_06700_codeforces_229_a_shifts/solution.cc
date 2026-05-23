#include <bits/stdc++.h>
using namespace std;
int c[10000];
int a[10000];
int b[10000];
int inf = 99999;
int main() {
  int n, i, j, k, t, m;
  int sign;
  int ans;
  char ch;
  while (scanf("%d%d", &n, &m) != EOF) {
    sign = 0;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) {
      scanf("%*c");
      for (j = 0; j < m; j++) {
        scanf("%c", &ch);
        b[j] = ch - '0';
        a[j] = inf;
      }
      if (sign == 1) continue;
      queue<int> q;
      for (j = 0; j < m; j++) {
        if (b[j]) {
          q.push(j);
          a[j] = 0;
        }
      }
      if (q.empty()) {
        sign = 1;
        continue;
      }
      while (!q.empty()) {
        int kk = q.front();
        q.pop();
        int pp = kk - 1;
        if (pp < 0) pp = m - 1;
        if (a[pp] == inf) {
          a[pp] = a[kk] + 1;
          q.push(pp);
        }
        pp = kk + 1;
        if (pp == m) pp = 0;
        if (a[pp] == inf) {
          a[pp] = a[kk] + 1;
          q.push(pp);
        }
      }
      for (k = 0; k < m; k++) {
        c[k] += a[k];
      }
    }
    int tmp = 0;
    if (sign)
      puts("-1");
    else {
      ans = 999999;
      for (i = 0; i < m; i++) {
        tmp = c[i];
        if (tmp < ans) ans = tmp;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
