#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> colors, first, last, euler_tour;
vector<bool> visit;
vector<vector<int> > ady;
void tour(int x) {
  if (visit[x]) return;
  visit[x] = true;
  euler_tour.push_back(x);
  first[x] = euler_tour.size() - 1;
  for (int i : ady[x]) {
    tour(i);
  }
  last[x] = euler_tour.size();
  euler_tour.push_back(x);
}
struct seg_tree {
  vector<long long> st, lazy;
  seg_tree(int n) : st(4 * n), lazy(4 * n) {}
  void push(int cur) {
    if (lazy[cur] != 0) {
      st[cur << 1] = lazy[cur << 1] = lazy[cur];
      st[cur << 1 | 1] = lazy[cur << 1 | 1] = lazy[cur];
      lazy[cur] = 0;
    }
  }
  void update(int cur, int b, int e, int l, int r, int c) {
    if (l <= b && e <= r) {
      st[cur] = 1LL << c;
      lazy[cur] = 1LL << c;
      return;
    }
    int m = (b + e) >> 1;
    push(cur);
    if (l < m) update(cur << 1, b, m, l, r, c);
    if (m < r) update(cur << 1 | 1, m, e, l, r, c);
    st[cur] = st[cur << 1] | st[cur << 1 | 1];
  }
  long long query(int cur, int b, int e, int l, int r) {
    if (l <= b && e <= r) return st[cur];
    int m = (b + e) >> 1;
    push(cur);
    long long ret = 0;
    if (l < m) ret = query(cur << 1, b, m, l, r);
    if (m < r) ret |= query(cur << 1 | 1, m, e, l, r);
    return ret;
  }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  colors.assign(n, 0);
  first.assign(n, 0);
  last.assign(n, 0);
  visit.assign(n, false);
  ady.assign(n, vector<int>(0));
  seg_tree st(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> colors[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    ady[u - 1].push_back(v - 1);
    ady[v - 1].push_back(u - 1);
  }
  tour(0);
  for (int i = 0; i < colors.size(); ++i) {
    st.update(1, 0, euler_tour.size(), first[i], first[i] + 1, colors[i]);
    st.update(1, 0, euler_tour.size(), last[i], last[i] + 1, colors[i]);
  }
  while (q--) {
    int o, c, v;
    cin >> o;
    if (o == 1) {
      cin >> v >> c;
      st.update(1, 0, euler_tour.size(), first[v - 1], last[v - 1] + 1, c);
    } else {
      cin >> v;
      long long finded =
          st.query(1, 0, euler_tour.size(), first[v - 1], last[v - 1] + 1);
      cout << __builtin_popcountll(finded) << "\n";
    }
  }
  return 0;
}
