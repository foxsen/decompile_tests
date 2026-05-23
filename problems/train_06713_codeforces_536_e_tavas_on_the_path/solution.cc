#include <bits/stdc++.h>
const int N = 100000 + 5;
int f[N];
int n, nq;
std::vector<int> edges[N];
int parent[N];
struct Node *nill;
struct Node {
  Node *ch[2], *fa;
  int lcnt, rcnt, color, sz;
  int sum;
  Node(int _color = 0, int _sz = 1) : color(_color), sz(_sz) {
    ch[0] = ch[1] = fa = nill;
    sum = f[color];
    lcnt = rcnt = color;
  }
  void up() {
    if (this == nill) return;
    sz = ch[0]->sz + ch[1]->sz + 1;
    lcnt = ch[0]->lcnt;
    rcnt = ch[1]->rcnt;
    sum = ch[0]->sum + ch[1]->sum;
    if (color == 1) {
      sum += f[ch[0]->rcnt + 1 + ch[1]->lcnt] - f[ch[0]->rcnt] - f[ch[1]->lcnt];
      if (ch[0]->lcnt == ch[0]->sz) {
        lcnt = ch[0]->lcnt + 1 + ch[1]->lcnt;
      }
      if (ch[1]->rcnt == ch[1]->sz) {
        rcnt = ch[1]->rcnt + 1 + ch[0]->rcnt;
      }
    }
  }
  bool isroot() { return fa == nill || fa->ch[0] != this && fa->ch[1] != this; }
  int d() { return fa->ch[1] == this; }
  void setc(Node *p, int c) {
    ch[c] = p;
    p->fa = this;
    up();
  }
  void rot() {
    int c = d(), cc = fa->d();
    Node *f = fa, *ff = fa->fa;
    f->setc(ch[c ^ 1], c);
    this->setc(f, c ^ 1);
    if (ff->ch[cc] == f)
      ff->setc(this, cc);
    else
      this->fa = ff;
  }
  Node *splay() {
    while (!isroot()) {
      if (!fa->isroot()) {
        fa->d() == d() ? fa->rot() : rot();
      }
      rot();
    }
    return this;
  }
  Node *access() {
    for (Node *p = this, *q = nill; p != nill;
         p->splay()->setc(q, 1), q = p, p = p->fa)
      ;
    return splay();
  }
};
Node pool[N], *node[N], *battery;
struct Unit {
  int u, v, w, id;
  Unit(int _u = 0, int _v = 0, int _w = 0, int _id = -1)
      : u(_u), v(_v), w(_w), id(_id) {}
  bool operator<(const Unit &rhs) const {
    if (w == rhs.w) return id > rhs.id;
    return w < rhs.w;
  }
};
Unit units[N + N];
int tot;
int answer[N];
void dfs(int u, int fa) {
  parent[u] = fa;
  if (fa != -1) {
    node[u]->fa = node[fa];
  }
  for (int v : edges[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
}
int main() {
  battery = pool;
  nill = new (battery++) Node(0, 0);
  nill->ch[0] = nill->ch[1] = nill->fa = nill;
  scanf("%d%d", &n, &nq);
  for (int i = 1; i < n; ++i) {
    scanf("%d", f + i);
  }
  for (int i = 0; i < n; ++i) {
    node[i] = new (battery++) Node();
  }
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    units[tot++] = Unit(a, b, c);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 0; i < nq; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    units[tot++] = Unit(a, b, c, i);
  }
  std::sort(units, units + tot);
  dfs(0, -1);
  for (int i = tot - 1; i >= 0; --i) {
    Unit &e = units[i];
    int a = e.u;
    int b = e.v;
    int id = e.id;
    if (id == -1) {
      if (parent[a] == b) {
        std::swap(a, b);
      }
      node[b]->splay()->color = 1;
      node[b]->up();
    } else {
      node[b]->access();
      node[a]->access();
      node[b]->splay();
      if (node[b]->fa == nill) {
        node[b]->access();
        answer[id] = node[a]->splay()->sum;
      } else {
        node[b]->fa->access();
        node[a]->splay();
        if (a != node[b]->fa - pool - 1) {
          answer[id] = node[a]->sum + node[b]->sum +
                       f[node[a]->lcnt + node[b]->lcnt] - f[node[a]->lcnt] -
                       f[node[b]->lcnt];
        } else {
          answer[id] = node[b]->sum;
        }
      }
    }
  }
  for (int i = 0; i < nq; ++i) {
    printf("%d\n", answer[i]);
  }
}
