#include <bits/stdc++.h>
using namespace std;
int s1[105], s2[105];
int a[105], b[105];
int tt[305];
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) tt[b[i]] = i;
  memset(s1, 0, sizeof s1);
  memset(s2, 0, sizeof s2);
  int boardl = min(T / 2, 100);
  int boardr = min(T - boardl, 100);
  for (int i = 1; i <= boardl; i++)
    for (int j = 1; j <= n; j++) {
      int nowm = 0;
      for (int k = 1; k <= tt[a[j]]; k++) nowm = max(nowm, s1[k]);
      s1[tt[a[j]]] = nowm + 1;
    }
  for (int i = 1; i <= boardr; i++)
    for (int j = n; j; j--) {
      int nowm = 0;
      for (int k = n; k >= tt[a[j]]; k--) nowm = max(nowm, s2[k]);
      s2[tt[a[j]]] = nowm + 1;
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int ans1 = 0, ans2 = 0;
    if (tt[b[i]] != tt[b[i - 1]]) {
      for (int j = 1; j <= tt[b[i]]; j++) ans1 = max(ans1, s1[j]);
      for (int j = tt[b[i]]; j <= n; j++) ans2 = max(ans2, s2[j]);
      ans = max(
          ans, ans1 + ans2 + (T - boardl - boardr) * (tt[b[i]] - tt[b[i - 1]]));
    }
  }
  printf("%d\n", ans);
  return 0;
}
