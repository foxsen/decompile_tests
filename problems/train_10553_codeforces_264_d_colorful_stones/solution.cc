#include <bits/stdc++.h>
using namespace std;
char a[1100000], b[1100000];
int cnt[10][10];
int main() {
  int la, lb, i, j, k;
  long long ans = 0;
  scanf("%s%s", &a, &b);
  la = strlen(a);
  lb = strlen(b);
  for (i = 0; i < la; i++) {
    if (a[i] == 'R') a[i] = 0;
    if (a[i] == 'G') a[i] = 1;
    if (a[i] == 'B') a[i] = 2;
  }
  for (i = 0; i < lb; i++) {
    if (b[i] == 'R') b[i] = 0;
    if (b[i] == 'G') b[i] = 1;
    if (b[i] == 'B') b[i] = 2;
  }
  for (i = j = k = 0; i < la; i++) {
    while (k < lb - 1 && b[k] != a[i]) {
      k++;
      cnt[b[k - 1]][b[k]]++;
    }
    ans += k - j + 1;
    if (i && a[i] != a[i - 1]) ans -= cnt[a[i]][a[i - 1]];
    if (k < lb - 1 && b[k] == a[i]) {
      k++;
      cnt[b[k - 1]][b[k]]++;
    }
    if (b[j] == a[i]) {
      if (j == lb - 1) break;
      j++;
      cnt[b[j - 1]][b[j]]--;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
