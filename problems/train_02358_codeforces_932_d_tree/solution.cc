#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 7;
const int M = 22;
long long w[N], last;
long long sum[N][M];
int nx[N][M], cnt = 1;
void add(int u, int v) {
  if (w[u] <= w[v])
    nx[u][0] = v;
  else {
    for (int i = 20; i >= 0; i--)
      if (nx[v][i] != -1 && w[nx[v][i]] < w[u]) v = nx[v][i];
    nx[u][0] = nx[v][0];
  }
  if (nx[u][0] != -1) sum[u][0] = w[nx[u][0]];
  for (int i = 1; i <= 20; i++) {
    if (nx[u][i - 1] == -1)
      nx[u][i] = -1;
    else {
      nx[u][i] = nx[nx[u][i - 1]][i - 1];
      sum[u][i] = sum[u][i - 1] + sum[nx[u][i - 1]][i - 1];
    }
  }
}
long long cal(int u, long long all) {
  if (w[u] > all) return 0;
  all -= w[u];
  long long ans = 1;
  for (int i = 20; i >= 0; i--) {
    if (u != -1 && all >= sum[u][i]) {
      all -= sum[u][i];
      ans += (1 << i);
      u = nx[u][i];
    }
  }
  return ans;
}
void init() {
  memset(sum, INF, sizeof(sum));
  memset(nx, -1, sizeof(nx));
  w[0] = INF;
}
int main() {
  init();
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      long long p, q;
      scanf("%lld", &p);
      scanf("%lld", &q);
      p ^= last;
      q ^= last;
      w[++cnt] = q;
      add(cnt, p);
    } else {
      long long p, q;
      scanf("%lld", &p);
      scanf("%lld", &q);
      p ^= last;
      q ^= last;
      last = cal(p, q);
      printf("%lld\n", last);
    }
  }
  return 0;
}
