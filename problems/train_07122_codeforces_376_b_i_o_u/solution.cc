#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, frm, to, mon, ret = 0;
  scanf("%d%d", &n, &m);
  vector<int> peop(n, 0);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &frm, &to, &mon);
    peop[frm - 1] += mon, peop[to - 1] -= mon;
  }
  for (int i = 0; i < n; i++) {
    mon = peop[i];
    if (mon < 0) mon = 0;
    ret += mon;
  }
  printf("%d\n", ret);
  return 0;
}
