#include <bits/stdc++.h>
using namespace std;
int tree[4 * 200005], cs[200005], ar[200005];
struct dt {
  int b, e, h, id, res;
} st[100005];
bool cmp1(dt x, dt y) { return x.b < y.b; }
bool cmp2(dt x, dt y) { return x.id < y.id; }
void update(int nd, int b, int e, int x, int v) {
  if (b > x || e < x) return;
  if (b == x && e == x) {
    tree[nd] = v;
    return;
  }
  int left = 2 * nd;
  int right = 2 * nd + 1;
  int md = (b + e) / 2;
  update(left, b, md, x, v);
  update(right, md + 1, e, x, v);
  tree[nd] = max(tree[left], tree[right]);
}
int query(int nd, int b, int e, int x, int y) {
  if (e < x || b > y) return 0;
  if (b >= x && e <= y) return tree[nd];
  int left = 2 * nd;
  int right = 2 * nd + 1;
  int md = (b + e) / 2;
  int p1 = query(left, b, md, x, y);
  int p2 = query(right, md + 1, e, x, y);
  return max(p1, p2);
}
int main() {
  int n;
  scanf("%d", &n);
  set<int> ss;
  for (int i = 1; i <= n; i++) {
    int b, h, e;
    scanf("%d%d", &b, &h);
    e = b + h - 1;
    st[i].b = b;
    st[i].e = e;
    st[i].h = h;
    st[i].id = i;
    st[i].res = -1;
    ss.insert(b);
    ss.insert(e);
  }
  map<int, int> mp;
  set<int>::iterator it;
  int m = 0;
  for (it = ss.begin(); it != ss.end(); it++) mp[*it] = ++m;
  sort(st + 1, st + n + 1, cmp1);
  int sz = ss.size();
  for (int i = 1; i <= n; i++) {
    int v = mp[st[i].b];
    ar[v] = 1;
    int u = mp[st[i].e];
    update(1, 1, sz, v, u);
  }
  cs[0] = 0;
  for (int i = 1; i <= sz; i++) cs[i] = cs[i - 1] + ar[i];
  for (int i = n; i >= 1; i--) {
    int b = mp[st[i].b];
    int e = mp[st[i].e];
    int p = query(1, 1, sz, b, e);
    int res = cs[p] - cs[b - 1];
    st[i].res = res;
    update(1, 1, sz, b, p);
  }
  sort(st + 1, st + n + 1, cmp2);
  for (int i = 1; i <= n; i++) {
    if (i == n)
      printf("%d\n", st[i].res);
    else
      printf("%d ", st[i].res);
  }
  return 0;
}
