#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * int(1e9);
const long long INFll = 1ll * INF * INF;
const int MOD = 1000000007;
const int MAX_A = 1000001;
int lp[MAX_A];
vector<int> pr;
void findPrimes() {
  for (int i = 2; i < MAX_A; ++i) {
    if (!lp[i]) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < pr.size() && pr[j] <= lp[i] && 1ll * pr[j] * i < MAX_A;
         ++j)
      lp[pr[j] * i] = pr[j];
  }
}
vector<int> fastFact(int x) {
  vector<int> res;
  while (x > 1) {
    if (res.empty() || res.back() != lp[x]) res.push_back(lp[x]);
    x /= lp[x];
  }
  return res;
}
vector<int> t;
int sz;
void modify(int x, int y) {
  t[x] = y;
  x /= 2;
  while (x) {
    t[x] = t[x * 2] * 1ll * t[x * 2 + 1] % MOD;
    x /= 2;
  }
}
int get(int v, int l, int r, int l1, int r1) {
  if (l > r1 || r < l1) return 1;
  if (l >= l1 && r <= r1) return t[v];
  return get(v * 2, l, (l + r) / 2, l1, r1) * 1ll *
         get(v * 2 + 1, (l + r) / 2 + 1, r, l1, r1) % MOD;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  findPrimes();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sz = 1;
  while (sz < n) sz *= 2;
  t.assign(sz * 2, 1);
  for (int i = 0; i < n; ++i) modify(i + sz, a[i]);
  int m;
  cin >> m;
  vector<pair<pair<int, int>, int> > q(m);
  for (int i = 0; i < m; ++i)
    cin >> q[i].first.first >> q[i].first.second, q[i].second = i;
  sort(q.begin(), q.end());
  vector<int> ans(m);
  vector<vector<int> > pos(MAX_A);
  vector<int> it(MAX_A, 1);
  vector<vector<int> > x(MAX_A);
  for (int i = 0; i < n; ++i) {
    vector<int> tmp = fastFact(a[i]);
    for (int j = 0; j < tmp.size(); ++j) {
      pos[tmp[j]].push_back(i);
      x[i].push_back(tmp[j]);
    }
  }
  int j = 0;
  for (int i = 0; i < MAX_A; ++i)
    if (!pos[i].empty())
      modify(sz + pos[i][0], t[sz + pos[i][0]] / i * (i - 1));
  for (int i = 0; i < m; ++i) {
    q[i].first.first--;
    q[i].first.second--;
    while (j < q[i].first.first) {
      for (int i = 0; i < x[j].size(); ++i) {
        int y = x[j][i];
        if (pos[y].size() == it[y])
          continue;
        else {
          modify(pos[y][it[y]] + sz, t[pos[y][it[y]] + sz] / y * (y - 1));
          it[y]++;
        }
      }
      j++;
    }
    ans[q[i].second] = get(1, 0, sz - 1, q[i].first.first, q[i].first.second);
  }
  for (int i = 0; i < m; ++i) cout << ans[i] << endl;
  if (0) cerr << "\nTIME = " << clock() << "\n";
  return 0;
}
