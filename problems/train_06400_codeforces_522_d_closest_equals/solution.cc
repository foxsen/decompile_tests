#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
const long long inf = 1e18;
long long n, m;
map<long long, long long> last;
vector<pair<long long, long long> > q[N];
long long a[N], nex[N];
long long t[4 * N];
long long ans[N];
long long get(int v, int tl, int tr, int L, int R) {
  if (tl > R || tr < L) return inf;
  if (L <= tl && tr <= R) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(v + v, tl, tm, L, R), get(v + v + 1, tm + 1, tr, L, R));
}
void upd(int v, int tl, int tr, int pos, long long x) {
  if (tl == tr) {
    t[v] = x;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    upd(v + v, tl, tm, pos, x);
  else
    upd(v + v + 1, tm + 1, tr, pos, x);
  t[v] = min(t[v + v], t[v + v + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i <= 4 * N; i++) t[i] = inf;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    q[l].push_back(make_pair(r, i));
  }
  for (int i = n; i >= 1; i--) {
    if (!last[a[i]]) {
      nex[i] = -1;
      last[a[i]] = i;
    } else {
      nex[i] = last[a[i]];
      last[a[i]] = i;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (nex[i] != -1) upd(1, 1, N, nex[i], nex[i] - i);
    for (int j = 0; j < q[i].size(); j++) {
      long long an = get(1, 1, N, i, q[i][j].first);
      if (an == inf)
        ans[q[i][j].second] = -1;
      else
        ans[q[i][j].second] = an;
    }
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << endl;
  return 0;
}
