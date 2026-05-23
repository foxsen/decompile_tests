#include <bits/stdc++.h>
using namespace std;
const int kMax = 100010;
struct Query {
  int ql, qr, qi;
  Query(int _ql, int _qr, int _qi) { ql = _ql, qr = _qr, qi = _qi; }
  bool operator<(const Query &rq) const { return qr < rq.qr; }
};
int N, Q;
int si[kMax], di[kMax], lf[kMax], rg[kMax], dfn, max_dpt;
vector<int> tree[kMax], vsi[kMax], vlf[kMax], vrg[kMax];
int qvi[kMax], qki[kMax];
vector<Query> vq[kMax];
int res[kMax], f[kMax];
map<int, int> rm_pos;
void read(void);
void prep(void);
void soups_on(void);
void dfs(int, int);
void update(int, int);
int query_sum(int);
inline int low_bit(int i) { return i & (-i); }
int main() {
  ios::sync_with_stdio(false);
  read(), prep(), soups_on();
  return 0;
}
void read(void) {
  string str;
  int prn, id_cnt;
  map<string, int> name_id;
  cin >> N;
  id_cnt = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> str >> prn;
    if (name_id.count(str) == 0) name_id[str] = id_cnt++;
    si[i] = name_id[str];
    tree[prn].push_back(i);
  }
  cin >> Q;
  for (int i = 0; i < Q; ++i) cin >> qvi[i] >> qki[i];
}
void prep(void) {
  int vi, ki, d, l, r;
  dfs(0, 0);
  for (int i = 0; i < Q; ++i) {
    vi = qvi[i], ki = qki[i], d = di[vi] + ki;
    if (d <= max_dpt) {
      l = lower_bound(vlf[d].begin(), vlf[d].end(), lf[vi]) - vlf[d].begin();
      r = lower_bound(vrg[d].begin(), vrg[d].end(), rg[vi]) - vrg[d].begin();
      vq[d].push_back(Query(l, r, i));
    }
  }
  for (int i = 1; i <= max_dpt; ++i) stable_sort(vq[i].begin(), vq[i].end());
}
void soups_on(void) {
  for (int i = 1; i <= max_dpt; ++i) {
    int p, q;
    p = q = 0;
    while (q < int(vq[i].size())) {
      Query &rq = vq[i][q];
      while (p < rq.qr) {
        if (rm_pos.count(vsi[i][p])) update(rm_pos[vsi[i][p]] + 1, -1);
        rm_pos[vsi[i][p]] = p;
        update(p + 1, 1);
        ++p;
      }
      res[rq.qi] = query_sum(rq.qr) - query_sum(rq.ql), ++q;
    }
    for (map<int, int>::iterator itr = rm_pos.begin(); itr != rm_pos.end();
         ++itr)
      update(itr->second + 1, -1);
    rm_pos.clear();
  }
  for (int i = 0; i < Q; ++i) cout << res[i] << "\n";
}
void dfs(int u, int lv) {
  di[u] = lv, vsi[lv].push_back(si[u]), vlf[lv].push_back(lf[u] = dfn), ++dfn;
  for (int i = 0; i < int(tree[u].size()); ++i) dfs(tree[u][i], lv + 1);
  vrg[lv].push_back(rg[u] = dfn), ++dfn, max_dpt = max(max_dpt, lv);
}
void update(int i, int dlt) {
  while (i < kMax) f[i] += dlt, i += low_bit(i);
}
int query_sum(int i) {
  int ret = 0;
  while (i > 0) ret += f[i], i -= low_bit(i);
  return ret;
}
