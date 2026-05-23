#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int table[5007][5007], n, m, k;
bool frq[5007][2];
struct q {
  int t, x, c;
} mem[N], a;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) scanf("%d%d%d", &mem[i].t, &mem[i].x, &mem[i].c);
  for (int i = k - 1; i >= 0; i--) {
    a = mem[i];
    if (a.t == 1) {
      if (frq[a.x][0]) continue;
      frq[a.x][0] = 1;
      for (int j = 1; j <= m; j++) {
        if (!table[a.x][j]) table[a.x][j] = a.c;
      }
    } else {
      if (frq[a.x][1]) continue;
      frq[a.x][1] = 1;
      for (int j = 1; j <= n; j++) {
        if (!table[j][a.x]) table[j][a.x] = a.c;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", table[i][j]);
    puts("");
  }
  return 0;
}
