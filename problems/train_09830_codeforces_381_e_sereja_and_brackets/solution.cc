#include <bits/stdc++.h>
using namespace std;
string str;
struct node_info {
  int c, f, s;
} var;
node_info tree[4000001];
inline void build(int node, int start, int end) {
  if (start == end) {
    tree[node].c = 0;
    if (str[start] == '(') {
      tree[node].f = 1;
      tree[node].s = 0;
    } else {
      tree[node].f = 0;
      tree[node].s = 1;
    }
  } else {
    int mid = (start + end) / 2;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);
    int extra = min(tree[2 * node + 1].f, tree[2 * node + 2].s);
    tree[node].c = tree[2 * node + 1].c + tree[2 * node + 2].c + extra;
    tree[node].f = tree[2 * node + 1].f + tree[2 * node + 2].f - extra;
    tree[node].s = tree[2 * node + 1].s + tree[2 * node + 2].s - extra;
  }
}
inline node_info query(int node, int start, int end, int l, int r) {
  if (start > end || start > r || end < l) {
    var.c = var.f = var.s = 0;
    return var;
  }
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  node_info p1 = query(2 * node + 1, start, mid, l, r);
  node_info p2 = query(2 * node + 2, mid + 1, end, l, r);
  int ans = p1.c + p2.c + min(p1.f, p2.s);
  node_info ret;
  ret.c = p1.c + p2.c + min(p1.f, p2.s);
  ret.f = p1.f + p2.f - min(p1.f, p2.s);
  ret.s = p1.s + p2.s - min(p1.f, p2.s);
  return ret;
}
int main() {
  cin >> str;
  build(0, 0, str.length() - 1);
  int q, l, r;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    int res = (query(0, 0, str.length() - 1, --l, --r).c) * 2;
    printf("%d\n", res);
  }
  return 0;
}
