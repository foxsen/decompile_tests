#include <bits/stdc++.h>
using namespace std;
int n, ab[233333], ba[233333], cnta, cntb, cnt;
char a[233333], b[233333];
struct data {
  int a, b;
} ans[233333];
int main() {
  scanf("%d%s%s", &n, a + 1, b + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 'a' && b[i] == 'b') ab[++cnta] = i;
    if (a[i] == 'b' && b[i] == 'a') ba[++cntb] = i;
  }
  if ((cnta + cntb) & 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i < cnta; i += 2) {
    ans[++cnt].a = ab[i];
    ans[cnt].b = ab[i + 1];
  }
  for (int i = 1; i < cntb; i += 2) {
    ans[++cnt].a = ba[i];
    ans[cnt].b = ba[i + 1];
  }
  if (cnta & 1) {
    ans[++cnt].a = ab[cnta];
    ans[cnt].b = ab[cnta];
    ans[++cnt].a = ab[cnta];
    ans[cnt].b = ba[cntb];
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i].a, ans[i].b);
  return 0;
}
