#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1000010;
int f[maxn], l, vis[maxn];
char s[maxn];
void getf(char *p) {
  int i, j, n = strlen(p);
  f[0] = f[1] = 0;
  for (i = 1; i < n; i++) {
    j = f[i];
    while (j && p[j] != p[i]) j = f[j];
    f[i + 1] = p[j] == p[i] ? j + 1 : 0;
  }
}
int main() {
  int i, j;
  while (~scanf("%s", s)) {
    l = strlen(s);
    getf(s);
    for (i = 0; i <= f[l]; i++) vis[i] = 0;
    for (i = 1; i < l; i++) vis[f[i]] = 1;
    i = f[l];
    int flag = 0;
    while (i) {
      if (vis[i]) {
        flag = 1;
        s[i] = '\0';
        break;
      }
      i = f[i];
    }
    if (!flag)
      printf("Just a legend\n");
    else
      printf("%s\n", s);
  }
  return 0;
}
