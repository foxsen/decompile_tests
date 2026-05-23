#include <bits/stdc++.h>
using namespace std;
struct apple {
  int v, nxt;
} edge[100011 * 4];
struct node {
  int l, r, lson, rson, sum, len;
} tree[100011 * 30];
int indexx[100011], tt[100011], root[100011], f[100011], max_son[100011],
    wgt[100011], fa[100011], top[100011], tot, siz, Root, deep[100011];
int sumx, ti, sum, ans, n, m;
void addedge(int x, int y) {
  edge[++tot].v = y;
  edge[tot].nxt = indexx[x];
  indexx[x] = tot;
}
void push_up(int now) {
  int l = tree[now].lson, r = tree[now].rson;
  tree[now].sum = tree[l].sum + tree[r].sum;
}
void build(int l, int r, int &now) {
  now = ++siz;
  tree[now].l = l;
  tree[now].r = r;
  tree[now].len = (r - l + 1);
  if (l == r) {
    tree[now].sum = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, tree[now].lson);
  build(mid + 1, r, tree[now].rson);
  push_up(now);
}
void add(int &now, int k, int p, int x) {
  now = ++siz;
  tree[now] = tree[k];
  if (tree[now].l == tree[now].r) {
    tree[now].sum++;
    return;
  }
  int mid = (tree[now].l + tree[now].r) / 2;
  if (p <= mid)
    add(tree[now].lson, tree[k].lson, p, x);
  else
    add(tree[now].rson, tree[k].rson, p, x);
  push_up(now);
}
int query(int now, int k, int l, int r) {
  if (l <= tree[now].l && tree[now].r <= r) {
    return tree[now].len - (tree[now].sum - tree[k].sum);
  }
  int mid = (tree[now].l + tree[now].r) / 2, ret = 0;
  if (l <= mid) ret += query(tree[now].lson, tree[k].lson, l, r);
  if (r > mid) ret += query(tree[now].rson, tree[k].rson, l, r);
  return ret;
}
void basic_dfs(int u, int dep) {
  deep[u] = dep;
  wgt[u] = 1;
  int t = indexx[u], vv, maxx = 0;
  while (t) {
    vv = edge[t].v;
    if (vv != fa[u]) {
      basic_dfs(vv, dep + 1);
      wgt[u] += wgt[vv];
      if (wgt[vv] > maxx) {
        max_son[u] = vv;
        maxx = wgt[vv];
      }
    }
    t = edge[t].nxt;
  }
}
void build_dfs(int u, int anc) {
  top[u] = anc;
  tt[u] = ++ti;
  f[ti] = u;
  if (max_son[u]) {
    build_dfs(max_son[u], anc);
  }
  int t = indexx[u], vv;
  while (t) {
    vv = edge[t].v;
    if (vv != max_son[u]) build_dfs(vv, vv);
    t = edge[t].nxt;
  }
}
int bin(int head, int tail, int i, int k, int num) {
  int s = tail, mid, ret;
  while (head <= tail) {
    mid = (head + tail) / 2;
    if (query(root[i], root[k], mid, s) >= num) {
      ret = mid;
      head = mid + 1;
    } else
      tail = mid - 1;
  }
  return ret;
}
int solve1(int x, int y, int i, int k) {
  int ret = 0, t;
  t = query(root[i], root[k], tt[x], tt[x]);
  sumx -= t;
  ret -= t;
  ret -= query(root[i], root[k], tt[y], tt[y]);
  while (top[x] != top[y]) {
    if (deep[top[x]] > deep[top[y]]) {
      t = query(root[i], root[k], tt[top[x]], tt[x]);
      ret += t;
      sumx += t;
      x = fa[top[x]];
    } else {
      ret += query(root[i], root[k], tt[top[y]], tt[y]);
      y = fa[top[y]];
    }
  }
  if (deep[x] >= deep[y]) {
    t = query(root[i], root[k], tt[y], tt[x]);
    ret += t;
    sumx += t;
  } else {
    ret += query(root[i], root[k], tt[x], tt[y]);
  }
  return ret;
}
int solve2(int x, int num, int i, int k) {
  int temp, ret;
  num += query(root[i], root[k], tt[x], tt[x]);
  while (x) {
    temp = query(root[i], root[k], tt[top[x]], tt[x]);
    if (num > temp) {
      num -= temp;
      x = fa[top[x]];
    } else {
      ret = bin(tt[top[x]], tt[x], i, k, num);
      return f[ret];
    }
  }
  return 0;
}
void Attack(int i) {
  int x;
  scanf("%d", &x);
  add(root[i], root[i - 1], tt[x], 1);
}
void Travel(int i) {
  int x, y, k, pre;
  root[i] = root[i - 1];
  scanf("%d%d%d%d", &x, &y, &k, &pre);
  sumx = 0;
  sum = solve1(x, y, i, pre);
  if (sum < k) {
    printf("-1\n");
    return;
  }
  if (sumx >= k) {
    ans = solve2(x, k, i, pre);
  } else {
    ans = solve2(y, sum - k + 1, i, pre);
  }
  printf("%d\n", ans);
}
int main() {
  int op;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &fa[i]);
    if (fa[i])
      addedge(fa[i], i);
    else
      Root = i;
  }
  basic_dfs(Root, 1);
  build_dfs(Root, Root);
  build(1, n, root[0]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &op);
    if (op == 1) {
      Attack(i);
    } else {
      Travel(i);
    }
  }
  return 0;
}
