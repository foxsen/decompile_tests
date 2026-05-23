#include <bits/stdc++.h>
int size[112345];
int main() {
  int n;
  int cur = 0;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    char c = getchar();
    if (c == '>')
      size[i] = 1;
    else
      size[i] = -1;
  }
  getchar();
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    size[i] *= a;
  }
  for (;;) {
    if (cur < 0 || cur >= n) break;
    if (size[cur] == 0) break;
    int t = cur;
    cur += size[cur];
    size[t] = 0;
  }
  if (cur < 0 || cur >= n)
    printf("FINITE\n");
  else
    printf("INFINITE\n");
  return 0;
}
