#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int x[maxn], y[maxn], p[maxn];
struct treenode {
  int L, R;
  double Up, Down, Max, Min, ans;
  void updata() {
    ans = 1.0 * p[L] * min(1.0 * x[L] / (x[L] + y[L]), 0.5);
    if (x[L] >= y[L])
      Up = 0;
    else {
      Up = 1.0 * p[L] * (x[L] + 1.0) / (x[L] + y[L] + 1.0);
      Up -= 1.0 * p[L] * x[L] / (x[L] + y[L]);
    }
    if (x[L]) {
      if (x[L] > y[L])
        Down = 0;
      else {
        Down = 1.0 * p[L] * x[L] / (x[L] + y[L]);
        Down -= 1.0 * p[L] * (x[L] - 1.0) / (x[L] - 1.0 + y[L]);
      }
    } else
      Down = 1e18;
  }
};
treenode tree[maxn * 4];
inline void push_up(int o) {
  tree[o].ans = tree[o << 1].ans + tree[o << 1 | 1].ans;
  tree[o].Up = max(tree[o << 1].Up, tree[o << 1 | 1].Up);
  tree[o].Down = min(tree[o << 1].Down, tree[o << 1 | 1].Down);
  if (tree[o << 1].Up > tree[o << 1 | 1].Up)
    tree[o].Max = tree[o << 1].Max;
  else
    tree[o].Max = tree[o << 1 | 1].Max;
  if (tree[o << 1].Down < tree[o << 1 | 1].Down)
    tree[o].Min = tree[o << 1].Min;
  else
    tree[o].Min = tree[o << 1 | 1].Min;
}
inline void build_tree(int L, int R, int o) {
  tree[o].L = L, tree[o].R = R, tree[o].ans = 0;
  if (L == R) tree[o].Min = tree[o].Max = L, tree[o].updata();
  if (R > L) {
    int mid = (L + R) >> 1;
    build_tree(L, mid, o * 2);
    build_tree(mid + 1, R, o * 2 + 1);
    push_up(o);
  }
}
inline void updata(int QL, int o) {
  int L = tree[o].L, R = tree[o].R;
  if (L == R) {
    tree[o].updata();
  } else {
    int mid = (L + R) >> 1;
    if (QL <= mid)
      updata(QL, o * 2);
    else
      updata(QL, o * 2 + 1);
    push_up(o);
  }
}
int main() {
  int n, t, q, mx, mi;
  scanf("%d%d%d", &n, &t, &q);
  for (int i = 1; i <= n; i++) p[i] = read();
  for (int i = 1; i <= n; i++) y[i] = read();
  build_tree(1, n, 1);
  while (t--) mx = tree[1].Max, x[mx]++, updata(mx, 1);
  while (q--) {
    int type, r;
    type = read(), r = read();
    if (type == 1)
      y[r]++;
    else
      y[r]--;
    updata(r, 1);
    while (1) {
      int mx = tree[1].Max;
      int mi = tree[1].Min;
      if (tree[1].Up <= tree[1].Down) break;
      x[mx]++, x[mi]--;
      updata(mx, 1);
      updata(mi, 1);
    }
    printf("%.12f\n", tree[1].ans);
  }
}
