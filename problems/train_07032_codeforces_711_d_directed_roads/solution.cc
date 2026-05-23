#include <bits/stdc++.h>
using namespace std;
int cas, cass;
int n, m, lll, ans;
long long aans;
long long e[200014];
int to[200014];
int t[200014];
bool mark[200014];
long long mi(int x, int y) {
  long long sum = 1;
  while (y) {
    if (y & 1) sum = (sum * x) % 1000000007;
    x = (x * x) % 1000000007;
    y >>= 1;
  }
  return sum;
}
void dfs(int u) {
  while (!mark[u]) {
    mark[u] = 1;
    t[u] = ++cas;
    u = to[u];
  }
  if (t[u] <= cass)
    aans = (aans * e[cas - cass]) % 1000000007;
  else {
    aans = (aans * ((e[cas - t[u] + 1] - 2 + 1000000007) % 1000000007)) %
           1000000007;
    aans = (aans * e[t[u] - 1 - cass]) % 1000000007;
  }
  return;
}
void init() {
  int i;
  e[0] = 1;
  for (i = 1; i < 200014; i++) e[i] = (e[i - 1] * 2) % 1000000007;
}
int main() {
  int i, j, k;
  init();
  while (~scanf("%d", &n)) {
    memset(mark, 0, sizeof(mark));
    for (i = 1; i <= n; i++) scanf("%d", &to[i]);
    aans = 1;
    cas = 0;
    for (i = 1; i <= n; i++) {
      if (mark[i]) continue;
      cass = cas;
      dfs(i);
    }
    printf("%I64d\n", aans);
  }
  return 0;
}
