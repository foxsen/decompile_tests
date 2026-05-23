#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
const long long N = 100010;
map<long long, long long> num[N];
long long kids[N] = {}, b = 0, tp[N] = {}, len[N] = {};
vector<long long> g[N];
long long dfs(long long n, long long p) {
  long long k = 1;
  if (g[n].size() == 1 && n != 1) {
    kids[n] = 1;
    return 1;
  }
  for (auto i : g[n]) {
    if (i != p) {
      k += dfs(i, n);
      tp[num[i][n]] = kids[i] * (b - kids[i]) * 2;
    }
  }
  kids[n] = k;
  return k;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  b = n;
  for (long long i = 1; i < n; i++) {
    long long a, b, l;
    cin >> a >> b >> l;
    g[a].push_back(b);
    g[b].push_back(a);
    num[a][b] = i;
    num[b][a] = i;
    len[i] = l;
  }
  dfs(1, -1);
  long long ans = 0;
  for (long long i = 1; i <= n - 1; i++) {
    ans += tp[i] * len[i];
  }
  double k = 3.0 / ((double)n * (n - 1));
  long long q;
  cin >> q;
  for (long long i = 1; i <= q; i++) {
    long long idx, new_len;
    cin >> idx >> new_len;
    ans -= (len[idx] - new_len) * tp[idx];
    cout << fixed << setprecision(10) << (double)ans * k << '\n';
    len[idx] = new_len;
  }
  return 0;
}
