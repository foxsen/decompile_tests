#include <bits/stdc++.h>
using namespace std;
struct Lt {
  int x;
  long long s;
} Q[400000 + 3];
int n, m, Now, Lx, Rx;
void Edit(int w, int l, int r, int x) {
  if (l == r) {
    Q[w].x = Q[w].s = Now;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    Edit(w << 1, l, mid, x);
  else
    Edit(w << 1 | 1, mid + 1, r, x);
  Q[w].x = max(Q[w << 1].x, Q[w << 1 | 1].x);
  Q[w].s = Q[w << 1].s + Q[w << 1 | 1].s;
}
long long Get(int w, int l, int r) {
  if (r < Lx || l > Rx) return 0;
  if (Lx <= l && r <= Rx) return Q[w].s;
  int mid = (l + r) >> 1;
  return Get(w << 1, l, mid) + Get(w << 1 | 1, mid + 1, r);
}
void Mod(int w, int l, int r) {
  if (r < Lx || l > Rx) return;
  if (Q[w].x < Now) return;
  if (l == r) {
    Q[w].x %= Now, Q[w].s = Q[w].x;
    return;
  }
  int mid = (l + r) >> 1;
  Mod(w << 1, l, mid);
  Mod(w << 1 | 1, mid + 1, r);
  Q[w].x = max(Q[w << 1].x, Q[w << 1 | 1].x);
  Q[w].s = Q[w << 1].s + Q[w << 1 | 1].s;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &Now), Edit(1, 1, n, i);
  }
  for (int i = 1; i <= m; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d%d", &Lx, &Rx);
      printf("%I64d\n", Get(1, 1, n));
    }
    if (ty == 2) {
      scanf("%d%d%d", &Lx, &Rx, &Now);
      Mod(1, 1, n);
    }
    if (ty == 3) {
      int x;
      scanf("%d%d", &x, &Now);
      Edit(1, 1, n, x);
    }
  }
}
