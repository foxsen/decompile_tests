#include <bits/stdc++.h>
using namespace std;
string s;
int m;
struct node {
  int ans, open, close;
  node *l, *r;
  node() {
    r = l = 0;
    ans = 0;
    open = 0;
    close = 0;
  }
};
node *merg(node *fir, node *sec) {
  node *ret = new node();
  ret->ans = fir->ans + sec->ans + min(fir->open, sec->close);
  ret->close = fir->close + sec->close - min(fir->open, sec->close);
  ret->open = fir->open + sec->open - min(fir->open, sec->close);
  return ret;
}
void build(node *me, int l, int r) {
  if (l == r) {
    if (s[l] == '(') {
      me->open = 1;
    } else {
      me->close = 1;
    }
    return;
  }
  int mid = (l + r) / 2;
  if (!(me->l)) {
    me->l = new node();
  }
  if (!(me->r)) {
    me->r = new node();
  }
  build(me->l, l, mid);
  build(me->r, mid + 1, r);
  me->ans = me->l->ans + me->r->ans + min(me->l->open, me->r->close);
  me->open = me->l->open + me->r->open - min(me->l->open, me->r->close);
  me->close = me->l->close + me->r->close - min(me->l->open, me->r->close);
}
node *get(node *me, int l, int r, int L, int R) {
  if (r < L || R < l) {
    node *noth = new node();
    return noth;
  }
  if (L <= l && r <= R) {
    return me;
  }
  int mid = (l + r) / 2;
  if (!(me->l)) {
    me->l = new node();
  }
  if (!(me->r)) {
    me->r = new node();
  }
  return merg(get(me->l, l, mid, L, R), get(me->r, mid + 1, r, L, R));
}
node *ok = new node();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  build(ok, 0, s.size() - 1);
  cin >> m;
  int l, r;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    cout << get(ok, 0, s.size() - 1, l - 1, r - 1)->ans * 2 << endl;
  }
  return 0;
}
