#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int st[maxn << 2];
int a[maxn], b[maxn];
vector<int> pos[maxn];
void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}
void update(int id, int l, int r, int u, int val) {
  if (l > u || r < u) return;
  if (l == r) {
    st[id] = val;
    return;
  }
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, u, val);
  update(id << 1 | 1, mid + 1, r, u, val);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}
int GetMin(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 1e9;
  if (u <= l && r <= v) return st[id];
  int mid = (l + r) >> 1;
  return min(GetMin(id << 1, l, mid, u, v),
             GetMin(id << 1 | 1, mid + 1, r, u, v));
}
string Solve() {
  int n;
  cin >> n;
  for (int i = (1), _b = (n); i <= _b; ++i) pos[i].clear();
  for (int i = (1), _b = (n); i <= _b; ++i) cin >> a[i];
  for (int i = (n), _b = (1); i >= _b; --i) pos[a[i]].push_back(i);
  for (int i = (1), _b = (n); i <= _b; ++i) cin >> b[i];
  build(1, 1, n);
  int l = 1;
  for (int i = (1), _b = (n); i <= _b; ++i) {
    if (pos[b[i]].empty()) return "NO";
    int nxt = pos[b[i]].back();
    pos[b[i]].pop_back();
    if (GetMin(1, 1, n, l, nxt) != b[i]) return "NO";
    update(1, 1, n, nxt, 1e9);
  }
  return "YES";
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = (1), _b = (q); i <= _b; ++i) cout << Solve() << '\n';
  return 0;
}
