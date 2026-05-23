#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 5000;
const int MAXM = MAXN - 1;
int n;
int head[MAXN];
int nxt[2 * MAXM], to[2 * MAXM];
int cnt[MAXM + 1];
int val[MAXM + 1][MAXN + 1];
void go(int at, int e) {
  cnt[e] = 0, val[e][0] = 0;
  for (int x = head[at]; x != -1; x = nxt[x]) {
    int ne = x >> 1;
    if (ne == e) continue;
    go(to[x], ne);
    for (int i = cnt[e] + cnt[ne]; i >= 0; --i) {
      int nval = INT_MAX;
      for (int i1 = max(0, i - cnt[ne]); i1 <= i && i1 <= cnt[e]; ++i1)
        if (val[e][i1] != INT_MAX && val[ne][i - i1] != INT_MAX &&
            val[e][i1] + val[ne][i - i1] < nval)
          nval = val[e][i1] + val[ne][i - i1];
      for (int i1 = max(0, i - cnt[ne]); i1 <= i && i1 <= cnt[e]; ++i1)
        if (val[e][i1] != INT_MAX && val[ne][i1 + cnt[ne] - i] != INT_MAX &&
            val[e][i1] + val[ne][i1 + cnt[ne] - i] + 1 < nval)
          nval = val[e][i1] + val[ne][i1 + cnt[ne] - i] + 1;
      val[e][i] = nval;
    }
    cnt[e] += cnt[ne];
  }
  if (cnt[e] == 0) cnt[e] = 1, val[e][0] = INT_MAX, val[e][1] = 0;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) head[i] = -1;
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    nxt[2 * i + 0] = head[a];
    head[a] = 2 * i + 0;
    to[2 * i + 0] = b;
    nxt[2 * i + 1] = head[b];
    head[b] = 2 * i + 1;
    to[2 * i + 1] = a;
  }
  if (n == 2) {
    printf("1\n");
    return;
  }
  int root = -1;
  for (int i = (0); i < (n); ++i)
    if (head[i] != -1 && nxt[head[i]] != -1) {
      root = i;
      break;
    }
  assert(root != -1);
  go(root, n - 1);
  printf("%d\n", val[n - 1][cnt[n - 1] / 2]);
}
int main() {
  run();
  return 0;
}
