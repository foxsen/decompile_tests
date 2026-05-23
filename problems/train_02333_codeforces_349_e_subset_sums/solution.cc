#include <bits/stdc++.h>
using namespace std;
const int B = 300;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (auto &ai : a) cin >> ai;
  vector<vector<int>> s(m);
  vector<long long> init_sum(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    s[i].resize(k);
    for (int &sij : s[i]) cin >> sij, sij--, init_sum[i] += a[sij];
  }
  auto is_large = [&](int i) { return s[i].size() >= B; };
  vector<vector<int>> ist_sz(m);
  vector<int> id;
  int large_num = 0;
  for (int i = 0; i < m; i++)
    if (is_large(i)) {
      vector<bool> b(n);
      for (int si : s[i]) b[si] = true;
      for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int sj : s[j]) cnt += b[sj];
        ist_sz[j].emplace_back(cnt);
      }
      id.emplace_back(i), large_num++;
    }
  vector<long long> large_sum(m), large_add(m), small_add(n);
  while (q--) {
    char op;
    cin >> op;
    int k;
    cin >> k;
    k--;
    if (op == '?') {
      if (is_large(k)) {
        cout << init_sum[k] + large_sum[k] << endl;
      } else {
        long long ans = init_sum[k];
        for (int sk : s[k]) ans += small_add[sk];
        for (int i = 0; i < large_num; i++)
          ans += large_add[id[i]] * ist_sz[k][i];
        cout << ans << endl;
      }
    }
    if (op == '+') {
      long long x;
      cin >> x;
      for (int i = 0; i < large_num; i++) large_sum[id[i]] += x * ist_sz[k][i];
      if (is_large(k))
        large_add[k] += x;
      else
        for (int sk : s[k]) small_add[sk] += x;
    }
  }
  return 0;
}
