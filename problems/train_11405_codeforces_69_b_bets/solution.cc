#include <bits/stdc++.h>
using namespace std;
struct Tt {
  int time, pro, num;
};
Tt ts[1000 + 123];
int main() {
  memset(ts, -1, sizeof(ts));
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int l, r, t, c;
    scanf("%d%d%d%d", &l, &r, &t, &c);
    for (int j = l; j <= r; ++j) {
      if (ts[j].time == -1 || ts[j].time > t) {
        ts[j].time = t;
        ts[j].pro = c;
      }
    }
  }
  int summ = 0;
  for (int i = 1; i <= n; ++i)
    if (ts[i].time != -1) summ += ts[i].pro;
  printf("%d\n", summ);
  return 0;
}
