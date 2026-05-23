#include <bits/stdc++.h>
using namespace std;
int n, ans, si;
const int inf = 1e9 + 9;
struct pp {
  int id, value;
  bool operator<(const pp &temp) const { return id < temp.id; }
};
struct point {
  int l, r, t;
};
point pt[110000];
struct segment_tree {
  int l, r, value, min_value, max_value, delta;
  int id_max, id_min;
};
segment_tree tree[410000], now, no;
void build(int left, int right, int id) {
  int l = 2 * id + 1, r = 2 * id + 2, mid = (left + right) >> 1;
  tree[id].l = left;
  tree[id].r = right;
  tree[id].min_value = inf;
  tree[id].max_value = -inf;
  tree[id].delta = 0;
  if (left == right) return;
  build(left, mid, l);
  build(mid + 1, right, r);
}
void zz(int id) {
  if (tree[id].delta == 0) return;
  int l = 2 * id + 1, r = 2 * id + 2;
  if (abs(tree[id].min_value) < inf) tree[id].min_value += tree[id].delta;
  if (tree[id].l != tree[id].r) {
    if (abs(tree[l].delta) < inf) tree[l].delta += tree[id].delta;
    if (abs(tree[r].delta) < inf) tree[r].delta += tree[id].delta;
  } else {
    if (abs(tree[id].value) < inf) tree[id].value += tree[id].delta;
  }
  tree[id].delta = 0;
}
void insert(int pos, int value, int min_value, int max_value, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  zz(id);
  if (tree[id].l == tree[id].r) {
    tree[id].value = value;
    tree[id].min_value = min_value;
    tree[id].max_value = max_value;
    tree[id].id_min = tree[id].l;
    tree[id].id_max = tree[id].l;
    return;
  }
  if (tree[l].r < pos)
    insert(pos, value, min_value, max_value, r);
  else
    insert(pos, value, min_value, max_value, l);
  zz(l);
  zz(r);
  if (tree[l].min_value < tree[r].min_value) {
    tree[id].min_value = tree[l].min_value;
    tree[id].id_min = tree[l].id_min;
  } else {
    tree[id].min_value = tree[r].min_value;
    tree[id].id_min = tree[r].id_min;
  }
  if (tree[l].max_value > tree[r].max_value) {
    tree[id].max_value = tree[l].max_value;
    tree[id].id_max = tree[l].id_max;
  } else {
    tree[id].max_value = tree[r].max_value;
    tree[id].id_max = tree[r].id_max;
  }
}
int qy(int pos, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  zz(id);
  if (tree[id].l == tree[id].r) return tree[id].value;
  if (tree[l].r < pos)
    return qy(pos, r);
  else
    return qy(pos, l);
}
segment_tree lower_bound(int pos, int id) {
  segment_tree res;
  int l = 2 * id + 1, r = 2 * id + 2;
  zz(id);
  if (tree[id].l == tree[id].r) {
    res = tree[id];
    if (tree[id].r >= pos) res.min_value = inf;
    return res;
  }
  if (tree[id].min_value == inf) {
    res = tree[id];
    return res;
  }
  if (tree[r].l < pos) {
    res = lower_bound(pos, r);
    if (res.min_value == inf) res = lower_bound(pos, l);
  } else
    res = lower_bound(pos, l);
  return res;
}
segment_tree upper_bound(int pos, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  segment_tree res;
  zz(id);
  if (tree[id].l == tree[id].r) {
    res = tree[id];
    if (tree[id].r <= pos) res.min_value = inf;
    return res;
  }
  if (tree[id].min_value == inf) {
    res = tree[id];
    return res;
  }
  if (tree[l].r > pos) {
    res = upper_bound(pos, l);
    if (res.min_value == inf) res = upper_bound(pos, r);
  } else
    res = upper_bound(pos, r);
  return res;
}
void del(int pos, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  zz(id);
  if (tree[id].l == tree[id].r) {
    tree[id].min_value = inf;
    tree[id].max_value = -inf;
    return;
  }
  if (tree[l].r < pos)
    del(pos, r);
  else
    del(pos, l);
  zz(l);
  zz(r);
  if (tree[l].min_value < tree[r].min_value) {
    tree[id].min_value = tree[l].min_value;
    tree[id].id_min = tree[l].id_min;
  } else {
    tree[id].min_value = tree[r].min_value;
    tree[id].id_min = tree[r].id_min;
  }
  if (tree[l].max_value > tree[r].max_value) {
    tree[id].max_value = tree[l].max_value;
    tree[id].id_max = tree[l].id_max;
  } else {
    tree[id].max_value = tree[r].max_value;
    tree[id].id_max = tree[r].id_max;
  }
}
void ins(int id) {
  int i, j, s, p, q, value, min_value, max_value;
  value = si + pt[id].t - 1;
  if (id + 1 < n)
    min_value = si + pt[id].t - pt[id + 1].l;
  else
    min_value = inf;
  now = lower_bound(id, 0);
  max_value = si + pt[id].t - 1 - now.value;
  if (now.min_value == inf) max_value = si + pt[id].t - 1;
  insert(id, value, min_value, max_value, 0);
  ans = si + pt[id].t - 1;
}
segment_tree query(int left, int right, int fk, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  segment_tree res, now;
  zz(id);
  if (tree[id].l == left && tree[id].r == right) return tree[id];
  if (tree[l].r < left) return query(left, right, fk, r);
  if (tree[r].l > right) return query(left, right, fk, l);
  now = query(left, tree[l].r, fk, l);
  res = query(tree[r].l, right, fk, r);
  if ((!fk && res.min_value > now.min_value) ||
      (fk && res.max_value < now.max_value))
    res = now;
  return res;
}
segment_tree qu(int left, int right, int cost, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  segment_tree res, now;
  zz(id);
  if (tree[id].l == left && tree[id].r == right) {
    if (tree[id].max_value < cost || tree[id].l == tree[id].r) return tree[id];
  }
  if (tree[l].r < left) return qu(left, right, cost, r);
  if (tree[r].l > right) return qu(left, right, cost, l);
  res = qu(tree[r].l, right, cost, r);
  if (res.max_value < cost) {
    now = qu(left, tree[l].r, cost, l);
    if (res.max_value < now.max_value) res = now;
  }
  return res;
}
void lazy(int pos, int delta, int l_delta, int id) {
  int l = 2 * id + 1, r = 2 * id + 2;
  zz(id);
  if (tree[id].l == tree[id].r) {
    tree[id].delta += delta;
    return;
  }
  if (tree[l].r < pos) {
    tree[l].delta += l_delta;
    lazy(pos, delta, l_delta, r);
  } else {
    tree[r].delta += delta;
    lazy(pos, delta, l_delta, l);
  }
  zz(l);
  zz(r);
  if (tree[l].min_value < tree[r].min_value) {
    tree[id].min_value = tree[l].min_value;
    tree[id].id_min = tree[l].id_min;
  } else {
    tree[id].min_value = tree[r].min_value;
    tree[id].id_min = tree[r].id_min;
  }
}
void fg(int ix, int &low, int &high) {
  int i, j, s, p, q, res, pr;
  segment_tree po;
  now = qu(ix + 1, n - 1, inf, 0);
  po = now;
  pr = now.max_value;
  now = qu(0, ix, now.max_value + 1, 0);
  if (now.max_value <= pr)
    low = max(ix + 1, po.id_max);
  else {
    no = query(now.id_max, n - 1, 0, 0);
    if (now.max_value >= no.min_value)
      low = max(ix + 1, po.id_max);
    else
      high = min(ix - 1, now.id_max - 1);
  }
}
int go(int ip) {
  int i, j, s, p, q, low, high, mid, id, va, vs, ne, res, v1, v2, vn;
  segment_tree ks;
  low = 0;
  now = lower_bound(ip, 0);
  high = now.l;
  while (low <= high) {
    mid = (low + high) >> 1;
    fg(mid, low, high);
  }
  if (high < 0) return -1;
  va = -inf;
  now = qu(high + 1, n - 1, inf, 0);
  now = qu(0, high, now.max_value + 1, 0);
  if (now.min_value == inf) return -1;
  no = query(now.id_max, n - 1, 0, 0);
  v1 = now.max_value;
  ks = no;
  id = now.id_max;
  va = min(now.max_value, no.min_value);
  now = qu(now.id_max + 1, n - 1, inf, 0);
  no = query(now.id_max, n - 1, 0, 0);
  if (va <= min(now.max_value, no.min_value)) {
    va = min(now.max_value, no.min_value);
    ks = no;
    v1 = now.max_value;
    id = now.id_max;
  }
  ne = max(ans - va + 1, pt[ip].l) + pt[ip].t - 1;
  if (ans - ne > 0 && ne <= pt[ip].r) {
    res = id + 1;
    del(id, 0);
    if (v1 <= ks.min_value) {
      lazy(id, -v1, 0, 0);
      now = lower_bound(id, 0);
      segment_tree nc = upper_bound(id, 0);
      if (now.min_value < inf) {
        int ie;
        if (nc.min_value < inf)
          ie = nc.l;
        else
          ie = ip;
        now.min_value = now.value + 1 - pt[ie].l;
        insert(now.l, now.value, now.min_value, now.max_value, 0);
      }
    } else {
      lazy(id, -ks.min_value, -inf, 0);
      now = upper_bound(ks.id_min, 0);
      if (now.min_value < inf) {
        now.max_value = pt[now.l].t;
        insert(now.l, now.value, now.min_value, now.max_value, 0);
      }
    }
    si = max(ans - va + 1, pt[ip].l);
    ins(ip);
  } else {
    res = -1;
    now = lower_bound(ip, 0);
    if (now.min_value < inf) {
      if (ip + 1 >= n)
        now.min_value = inf;
      else
        now.min_value = now.value + 1 - pt[ip + 1].l;
      insert(now.l, now.value, now.min_value, now.max_value, 0);
    }
  }
  return res;
}
int main() {
  int tst = 0, i, j, s, p, q;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &pt[i].l, &pt[i].r, &pt[i].t);
  }
  build(0, n - 1, 0);
  ans = 0;
  for (i = 0; i < n; i++) {
    si = max(ans + 1, pt[i].l);
    if (si + pt[i].t - 1 <= pt[i].r) {
      ins(i);
      printf("0 ");
    } else
      printf("%d ", go(i));
  }
  printf("\n");
  return 0;
}
