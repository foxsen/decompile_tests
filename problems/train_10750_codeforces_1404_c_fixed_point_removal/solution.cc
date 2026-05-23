#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
int n, q, a[N], ans[N], it[4 * N], b[N];
vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  return (x.first.second < y.first.second);
}
void upd(int id, int l, int r, int pos, int val) {
  if (pos < l || r < pos) return;
  if (l == r) {
    it[id] += val;
    return;
  }
  int mid = (l + r) / 2;
  upd(2 * id, l, mid, pos, val);
  upd(2 * id + 1, mid + 1, r, pos, val);
  it[id] = it[2 * id] + it[2 * id + 1];
}
int get_pos(int id, int l, int r, int pos) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (it[2 * id] >= pos)
    return get_pos(2 * id, l, mid, pos);
  else
    return get_pos(2 * id + 1, mid + 1, r, pos - it[2 * id]);
}
int get_sum(int id, int l, int r, int l1, int r1) {
  if (r1 < l || r < l1) return 0;
  if (l1 <= l && r <= r1) return it[id];
  int mid = (l + r) / 2;
  return get_sum(2 * id, l, mid, l1, r1) +
         get_sum(2 * id + 1, mid + 1, r, l1, r1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back({{l, r}, i});
  }
  sort(v.begin(), v.end(), cmp);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > i) continue;
    int tmp = i - a[i];
    if (tmp <= cnt) {
      if (tmp == 0) {
        b[i] = i;
        upd(1, 1, n, i, 1);
      } else {
        tmp = cnt - tmp + 1;
        b[i] = get_pos(1, 1, n, tmp);
        upd(1, 1, n, b[i], 1);
      }
      cnt++;
    }
  }
  int cur = n + 1;
  for (int i = 0; i < q; i++) {
    int tmp = n - v[i].first.second + 1;
    for (int j = tmp; j < cur; j++) {
      if (b[j] == 0) continue;
      upd(1, 1, n, b[j], -1);
    }
    ans[v[i].second] = get_sum(1, 1, n, v[i].first.first + 1, n);
    cur = tmp;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}
