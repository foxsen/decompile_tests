#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 5e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m;
vector<int> g[N];
int x[N], y[N], pos[N];
long long pref[N], suff[N], ans[N];
pair<int, int> id[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    id[i] = make_pair(x[i] - y[i], i);
  }
  sort(id + 1, id + n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + x[id[i].second];
    pos[id[i].second] = i;
  }
  for (long long i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + y[id[i].second];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int j = 1; j <= n; j++) {
    int i = id[j].second;
    int cnt_pre = j - 1;
    int cnt_su = n - cnt_pre - 1;
    long long sum_pre = pref[j - 1];
    long long sum_su = suff[j + 1];
    for (int to : g[i]) {
      if (pos[to] < pos[i])
        sum_pre -= x[to], cnt_pre--;
      else
        sum_su -= y[to], cnt_su--;
    }
    ans[id[j].second] =
        sum_pre + sum_su + cnt_pre * (long long)y[i] + cnt_su * (long long)x[i];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
