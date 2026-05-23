#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, NIL = -1;
const int MAXS = 5e5 + 10, MAXM = 5e4 + 10, MAXQ = 5e5 + 10;
const int sam_node = (MAXS + MAXM) * 2;
struct Graph {
  int to[sam_node * 2], nxt[sam_node * 2], head[sam_node], e;
  void clear() {
    memset(head, NIL, sizeof(head));
    e = 0;
  }
  Graph() { clear(); }
  void addedge(int f, int t) { to[e] = t, nxt[e] = head[f], head[f] = e++; }
  void addtwo(int u, int v) { addedge(u, v), addedge(v, u); }
};
namespace SGT {
int NIL = 0;
int ls[MAXM * 20], rs[MAXM * 20], mx[MAXM * 20], idx[MAXM * 20], sgttail;
inline int newnode() {
  ls[sgttail] = rs[sgttail] = NIL;
  mx[sgttail] = 0;
  return sgttail++;
}
inline void init() {
  ls[NIL] = rs[NIL] = 0;
  mx[NIL] = -5;
  sgttail = 1;
}
inline void update(int now) {
  if (mx[ls[now]] >= mx[rs[now]]) {
    mx[now] = mx[ls[now]];
    idx[now] = idx[ls[now]];
  } else {
    mx[now] = mx[rs[now]];
    idx[now] = idx[rs[now]];
  }
}
void insert(int l, int r, int &now, int id) {
  if (now == NIL) now = newnode();
  if (l == r) {
    ++mx[now];
    idx[now] = id;
    return;
  }
  if (id <= ((l + r) >> 1))
    insert(l, ((l + r) >> 1), ls[now], id);
  else
    insert(((l + r) >> 1) + 1, r, rs[now], id);
  update(now);
}
int merge(int l, int r, int rt1, int rt2) {
  if (rt1 == NIL) return rt2;
  if (rt2 == NIL) return rt1;
  if (l == r) {
    mx[rt1] += mx[rt2];
    idx[rt1] = l;
    return rt1;
  }
  int rl = merge(l, ((l + r) >> 1), ls[rt1], ls[rt2]),
      rr = merge(((l + r) >> 1) + 1, r, rs[rt1], rs[rt2]);
  ls[rt1] = rl, rs[rt1] = rr;
  update(rt1);
  return rt1;
}
pair<int, int> ask_max(int l, int r, int now, int st, int en) {
  if (now == NIL) return make_pair(max(st, l), 0);
  if (st <= l && r <= en) return make_pair(idx[now], mx[now]);
  if (en <= ((l + r) >> 1)) return ask_max(l, ((l + r) >> 1), ls[now], st, en);
  if (st > ((l + r) >> 1))
    return ask_max(((l + r) >> 1) + 1, r, rs[now], st, en);
  pair<int, int> al = ask_max(l, ((l + r) >> 1), ls[now], st, en),
                 ar = ask_max(((l + r) >> 1) + 1, r, rs[now], st, en);
  return (al.second >= ar.second) ? al : ar;
}
}  // namespace SGT
int to[sam_node][26], len[sam_node], parent[sam_node], samtail;
inline int newnode(int l) {
  len[samtail] = l;
  return samtail++;
}
int extend(int ch, int last) {
  int p = last, now = (to[p][ch] == NIL) ? newnode(len[p] + 1) : NIL;
  for (; p != NIL && to[p][ch] == NIL; p = parent[p]) to[p][ch] = now;
  if (p == NIL)
    parent[now] = 0;
  else {
    int q = to[p][ch];
    if (len[q] == len[p] + 1) {
      if (now == NIL)
        now = q;
      else
        parent[now] = q;
    } else {
      int nq = newnode(len[p] + 1);
      parent[nq] = parent[q];
      memcpy(to[nq], to[q], sizeof(to[q]));
      parent[q] = nq;
      if (now == NIL)
        now = nq;
      else
        parent[now] = nq;
      for (; p != NIL && to[p][ch] == q; p = parent[p]) to[p][ch] = nq;
    }
  }
  return now;
}
void init_sam() {
  memset(to, NIL, sizeof(to));
  len[0] = 0;
  parent[0] = NIL;
  samtail = 1;
}
struct Query {
  int idx, l, st, en;
  Query() {}
  Query(int idx, int l, int st, int en) : idx(idx), l(l), st(st), en(en) {}
};
Graph tr;
char str[MAXS];
int m, q, root[sam_node];
pair<int, int> ans[MAXQ];
vector<Query> tmp[sam_node], qt[sam_node];
void get_parent() {
  for (int i = 1; i < samtail; ++i) {
    tr.addedge(parent[i], i);
  }
}
void get_qt(int now) {
  static pair<int, int> stk[sam_node];
  static int stail = 0;
  stk[stail++] = make_pair(len[now], now);
  for (int i = 0; i < (int)tmp[now].size(); ++i) {
    int idx =
        lower_bound(stk, stk + stail, make_pair(tmp[now][i].l, -5))->second;
    qt[idx].push_back(tmp[now][i]);
  }
  for (int i = tr.head[now]; i != NIL; i = tr.nxt[i]) {
    get_qt(tr.to[i]);
  }
  --stail;
}
void get_ans(int now) {
  for (int i = tr.head[now]; i != NIL; i = tr.nxt[i]) {
    get_ans(tr.to[i]);
    root[now] = SGT::merge(1, m, root[now], root[tr.to[i]]);
  }
  for (int i = 0; i < (int)qt[now].size(); ++i) {
    ans[qt[now][i].idx] =
        SGT::ask_max(1, m, root[now], qt[now][i].st, qt[now][i].en);
  }
}
void init() {
  init_sam();
  memset(root, 0, sizeof(root));
  SGT::init();
}
int main() {
  scanf("%s", str);
  init();
  int len = strlen(str);
  static int pos[MAXS];
  int prv = 0;
  for (int i = 0; i < len; ++i) {
    prv = extend(str[i] - 'a', prv);
    pos[i + 1] = prv;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%s", str);
    int len = strlen(str), prv = 0;
    for (int j = 0; j < len; ++j) {
      prv = extend(str[j] - 'a', prv);
      SGT::insert(1, m, root[prv], i);
    }
  }
  get_parent();
  scanf("%d", &q);
  for (int i = 0, l, r, st, en; i < q; ++i) {
    scanf("%d%d%d%d", &st, &en, &l, &r);
    tmp[pos[r]].push_back(Query(i, r - l + 1, st, en));
  }
  get_qt(0);
  get_ans(0);
  for (int i = 0; i < q; ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
