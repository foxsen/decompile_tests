#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct edge {
  int nxt, to, id;
} e[N * 3];
int fir[N];
int n, m, a[N], tab[19][N], key[N << 2];
int ans[N * 3];
inline void addedge(int x, int y, int id) {
  static int cnt = 0;
  e[++cnt] = (edge){fir[x], y, id};
  fir[x] = cnt;
}
inline void Build(int D = 0, int L = 1, int R = n) {
  if (L == R) {
    tab[D][L] = a[L];
    return;
  }
  Build(D + 1, L, ((L + R) >> 1));
  Build(D + 1, ((L + R) >> 1) + 1, R);
  int l = L, r = ((L + R) >> 1) + 1;
  for (int i = L; i <= R; i++) {
    if (r > R || (l <= ((L + R) >> 1) && tab[D + 1][l] < tab[D + 1][r]))
      tab[D][i] = tab[D + 1][l++];
    else
      tab[D][i] = tab[D + 1][r++];
  }
}
inline void Upd(int r, int &val, int x = 1, int L = 1, int R = n, int D = 0) {
  if (L >= r) return;
  if (R < r) {
    int t = 1e9;
    int p = lower_bound(tab[D] + L, tab[D] + R + 1, a[r]) - tab[D];
    if (p <= R) t = min(t, tab[D][p] - a[r]);
    if (L < p) t = min(t, a[r] - tab[D][p - 1]);
    if (t >= val) return;
    if (L == R) {
      key[x] = min(key[x], t);
      val = min(val, key[x]);
      return;
    }
  }
  Upd(r, val, x << 1 | 1, ((L + R) >> 1) + 1, R, D + 1);
  Upd(r, val, x << 1, L, ((L + R) >> 1), D + 1);
  key[x] = min(key[x << 1], key[x << 1 | 1]);
  val = min(val, key[x]);
}
inline int Que(int l, int r, int x = 1, int L = 1, int R = n) {
  if (l <= L && R <= r) return key[x];
  int res = 1e9;
  if (l <= ((L + R) >> 1)) res = Que(l, r, x << 1, L, ((L + R) >> 1));
  if (((L + R) >> 1) < r)
    res = min(res, Que(l, r, x << 1 | 1, ((L + R) >> 1) + 1, R));
  return res;
}
int main() {
  memset(key, 63, sizeof key);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1, l, r; i <= m; i++) {
    scanf("%d%d", &l, &r);
    addedge(r, l, i);
  }
  Build();
  for (int i = 2, t; i <= n; i++) {
    t = 1e9;
    Upd(i, t);
    for (int j = fir[i]; j; j = e[j].nxt) ans[e[j].id] = Que(e[j].to, i);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
