#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int N = 1e6 + 5;
ll seg[6 * N];
ll lazy[6 * N];
ll qu(int node, int l, int r) {
  if (lazy[node]) {
    seg[node] += lazy[node];
    if (l < r) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (seg[node] <= 0) return -1;
  if (l == r) return l;
  int m = (l + r) / 2;
  auto ret = qu(2 * node + 1, m + 1, r);
  if (ret == -1) ret = qu(2 * node, l, m);
  return ret;
}
void upd_rn(int node, int l, int r, int x, int y, int val) {
  if (lazy[node]) {
    seg[node] += lazy[node];
    if (l < r) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (l > y or r < x) return;
  if (l >= x and r <= y) {
    seg[node] += val;
    lazy[2 * node] += val;
    lazy[2 * node + 1] += val;
    return;
  }
  int m = (l + r) / 2;
  upd_rn(2 * node, l, m, x, y, val);
  upd_rn(2 * node + 1, m + 1, r, x, y, val);
  seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    upd_rn(1, 1, N, 1, a[i], 1);
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    upd_rn(1, 1, N, 1, b[i], -1);
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      --pos;
      if (a[pos] < val)
        upd_rn(1, 1, N, a[pos] + 1, val, 1);
      else if (a[pos] > val)
        upd_rn(1, 1, N, val + 1, a[pos], -1);
      a[pos] = val;
    } else {
      int pos, val;
      cin >> pos >> val;
      --pos;
      if (b[pos] < val)
        upd_rn(1, 1, N, b[pos] + 1, val, -1);
      else if (b[pos] > val)
        upd_rn(1, 1, N, val + 1, b[pos], 1);
      b[pos] = val;
    }
    cout << qu(1, 1, N) << '\n';
  }
}
void InputSetup() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main(void) {
  auto start = chrono::high_resolution_clock::now();
  InputSetup();
  solve();
  auto finish = chrono::high_resolution_clock::now();
  cerr << "Time elapsed: "
       << (chrono::duration<long double>(finish - start)).count() << "s\n";
}
