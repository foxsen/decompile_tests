#include <bits/stdc++.h>
using namespace std;
const int MAX = int(1e5) + 10;
const int oo = 1000000005;
struct line {
  int h, l, r, dp;
  set<int> ptr;
  line() {}
  line(int h, int l, int r) : h(h), l(l), r(r), dp(-1) {}
  bool operator<(const line &B) const {
    if (h != B.h) return h < B.h;
    return r < B.r;
  }
} L[MAX];
struct part {
  int l, r, id;
  bool operator<(const part &B) const { return l < B.l; }
};
int N, T;
set<part> S, cov;
int overlap(int lo1, int hi1, int lo2, int hi2) {
  int l = max(lo1, lo2);
  int r = min(hi1, hi2);
  return r - l;
}
bool can(int i, part p) {
  int over_seg = overlap(L[i].l, L[i].r, L[p.id].l, L[p.id].r);
  int over_part = overlap(L[i].l, L[i].r, p.l, p.r);
  return over_part > 0 && over_part == over_seg;
}
void process(int i, part p) {
  if (overlap(L[i].l, L[i].r, p.l, p.r) <= 0) {
    S.insert(p);
    return;
  }
  if (p.l <= L[i].l && L[i].r <= p.r) {
    if (p.l < L[i].l) S.insert((part){p.l, L[i].l, p.id});
    if (L[i].r < p.r) S.insert((part){L[i].r, p.r, p.id});
  } else if (p.l <= L[i].r && L[i].r <= p.r) {
    if (L[i].r < p.r) S.insert((part){L[i].r, p.r, p.id});
  } else if (p.l <= L[i].l && L[i].l <= p.r) {
    if (p.l < L[i].l) S.insert((part){p.l, L[i].l, p.id});
  }
}
void make_tree() {
  S.insert((part){-oo, oo, 0});
  for (int i = 1; i < N; i++) {
    cov.clear();
    int l = L[i].l, r = L[i].r;
    part p = (part){l, r, i};
    set<part>::iterator beg = S.upper_bound(p), end;
    beg--;
    set<part>::iterator it = beg;
    for (; it != S.end() && it->l < r; it++) {
      if (can(i, *it)) L[i].ptr.insert(it->id);
      if (!(l <= it->l && it->r <= r)) cov.insert(*it);
    }
    end = it;
    S.erase(beg, end);
    for (it = cov.begin(); it != cov.end(); it++) process(i, *it);
    S.insert(p);
  }
}
int dfs(int v) {
  int &ret = L[v].dp;
  if (ret != -1) return ret;
  set<int> &ptr = L[v].ptr;
  if (v == 0) return ret = 2 * oo;
  if (ptr.size() == 0) return ret = -2 * oo;
  for (set<int>::iterator it = ptr.begin(); it != ptr.end(); it++) {
    int over = overlap(L[v].l, L[v].r, L[*it].l, L[*it].r);
    int dp = dfs(*it);
    ret = max(ret, min(dp, over));
  }
  return ret;
}
int main() {
  cin >> N >> T;
  L[N] = line(oo, -oo, oo);
  for (int i = 0; i < N; i++) {
    int h, l, r;
    cin >> h >> l >> r;
    L[i] = line(h, l, r);
  }
  N++;
  L[N++] = line(0, -oo, oo);
  sort(L, L + N);
  make_tree();
  int ans = dfs(N - 1);
  cout << ans << endl;
  return 0;
}
