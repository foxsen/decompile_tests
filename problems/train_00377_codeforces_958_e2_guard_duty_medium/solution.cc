#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const int maxk = 5010;
const long long oo = 1e13;
int k, n, a[maxn];
long long f[3][maxk][3];
vector<pair<long long, int> > ti;
int main() {
  cin >> k >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) ti.push_back(make_pair(a[i] - a[i - 1], i));
  sort(ti.begin(), ti.end());
  int le = ti.size();
  set<int> t4k;
  for (int i = 0; i < min(2 * k, le); i++) {
    t4k.insert(a[ti[i].second]);
    t4k.insert(a[ti[i].second - 1]);
  }
  n = 1;
  for (auto x : t4k) a[n++] = x;
  n--;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= k; j++)
      for (int tt = 0; tt < 2; tt++) f[i][j][tt] = oo;
  int t = 0;
  f[1 - t][0][0] = 0;
  for (int tim = 2; tim <= n; tim++) {
    for (int j = 1; j <= k; j++)
      for (int tt = 0; tt < 2; tt++) f[t][j][tt] = oo;
    for (int j = 1; j <= min(tim, k); j++) {
      f[t][j][0] = min(f[1 - t][j][1], f[1 - t][j][0]);
      f[t][j][1] = min(f[t][j][1], f[1 - t][j - 1][0] + a[tim] - a[tim - 1]);
      f[t][j][1] = min(f[t][j][1], f[t][j][0]);
    }
    t = 1 - t;
  }
  cout << min(f[1 - t][k][0], f[1 - t][k][1]);
}
