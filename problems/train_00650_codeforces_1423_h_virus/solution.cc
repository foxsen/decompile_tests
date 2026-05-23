#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int components, n, m, k;
ifstream in;
ofstream out;
map<pair<int, int>, int> start;
int ans[N], p[N], s[N];
vector<pair<int, int> > need[N + 1];
struct Query {
  int u, v;
  bool must_rollback;
};
vector<Query> tree[N + 1 << 2];
struct Save {
  int u, v, sizeU, sizeV;
};
stack<Save> ops;
int find_set(int x) { return x == p[x] ? x : find_set(p[x]); }
bool union_sets(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return false;
  if (s[x] < s[y]) swap(x, y);
  p[y] = x;
  ops.push({x, y, s[x], s[y]});
  s[x] += s[y];
  s[y] = s[x];
  return true;
}
void rollback() {
  if (ops.empty()) return;
  Save op = ops.top();
  ops.pop();
  p[op.u] = op.u;
  p[op.v] = op.v;
  s[op.u] = op.sizeU;
  s[op.v] = op.sizeV;
}
void add_query(int l, int r, int L, int R, Query &q, int p) {
  if (l > R || L > r) return;
  if (L <= l && R >= r) {
    tree[p].push_back(q);
  } else {
    int m = l + r >> 1;
    add_query(l, m, L, R, q, p << 1);
    add_query(m + 1, r, L, R, q, p << 1 | 1);
  }
}
void traverse(int l, int r, int p) {
  for (Query &q : tree[p]) {
    q.must_rollback = union_sets(q.u, q.v);
  }
  if (l == r) {
    for (auto [x, index] : need[l]) {
      ans[index] = s[find_set(x)];
    }
  } else {
    int m = l + r >> 1;
    traverse(l, m, p << 1);
    traverse(m + 1, r, p << 1 | 1);
  }
  for (Query q : tree[p]) {
    if (q.must_rollback) {
      rollback();
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) p[i] = i, s[i] = 1;
  int timer = 1, cnt = 0;
  vector<int> days = {0};
  vector<int> u, v, id, d;
  for (int i = 1; i <= m; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, q;
      cin >> p >> q;
      u.push_back(p);
      v.push_back(q);
      id.push_back(i);
      d.push_back(days.size() - 1);
    } else if (type == 2) {
      int x;
      cin >> x;
      need[i].push_back({x, ++cnt});
    } else {
      days.push_back(i);
    }
  }
  for (int i = 0; i < v.size(); ++i) {
    int L = id[i], R = N;
    Query q = {u[i], v[i], 0};
    if (days.size() > d[i] + k) {
      R = days[d[i] + k] - 1;
    }
    add_query(1, N, L, R, q, 1);
  }
  traverse(1, N, 1);
  for (int i = 1; i <= cnt; ++i) {
    cout << ans[i] << ' ';
  }
}
