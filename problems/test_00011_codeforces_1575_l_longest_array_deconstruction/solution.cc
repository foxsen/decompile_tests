#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 123;
vector<int> ST(4 * N, 0);
void update(int k, int l, int r, int idx, int val) {
  if (l > idx || r < idx) return;
  if (l == r && l == idx) {
    ST[k] = val;
    return;
  }
  int m = (l + r) >> 1;
  update(k << 1, l, m, idx, val);
  update(k << 1 | 1, m + 1, r, idx, val);
  ST[k] = max(ST[k << 1], ST[k << 1 | 1]);
}
int getLis(int k, int l, int r, int from, int to) {
  if (l > r) return 0;
  if (l > to || from > r) return 0;
  if (from <= l && r <= to) return ST[k];
  int m = (l + r) >> 1;
  return max(getLis(k << 1, l, m, from, to),
             getLis(k << 1 | 1, m + 1, r, from, to));
}
void TestCase() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& x : v) cin >> x;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    if (i - v[i] + 1 >= 0) {
      p.push_back({i - v[i] + 1, v[i]});
    }
  }
  sort(p.begin(), p.end());
  vector<int> LIS(2 * N + 5, 0);
  int answer = 0;
  for (int i = 0; i < p.size(); i++) {
    LIS[p[i].second] = getLis(1, 0, n, 0, p[i].second - 1) + 1;
    update(1, 0, n, p[i].second, LIS[p[i].second]);
    answer = max(answer, LIS[p[i].second]);
  }
  cout << answer << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int T = 1;
  while (T--) {
    TestCase();
  }
}
