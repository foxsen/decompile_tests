#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, k, a;
  int cot1[10005] = {0}, cot2[10005] = {0};
  scanf("%d%d", &n, &m);
  int maxx = 0;
  int flag = 0;
  while (m--) {
    scanf("%d", &k);
    memset(cot1, 0, sizeof(cot1));
    memset(cot2, 0, sizeof(cot2));
    maxx = -1;
    int ff;
    while (k--) {
      scanf("%d", &a);
      if (a < 0)
        cot1[-a] = 1;
      else
        cot2[a] = 1;
      maxx = max(maxx, abs(a));
    }
    int i;
    ff = 0;
    for (i = 0; i <= maxx; i++) {
      if (cot1[i] == cot2[i] && cot1[i] == 1) {
        ff = 1;
        break;
      }
    }
    if (ff == 0) flag = 1;
  }
  if (flag == 1)
    puts("YES");
  else
    puts("NO");
  return 0;
}
