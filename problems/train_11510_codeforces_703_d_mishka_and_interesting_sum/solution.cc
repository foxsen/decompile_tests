#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15, mod = 1e9 + 7;
long long arr[1000001], st[4 * 1000001], pre[1000001], ans[1000001];
std::vector<pair<long long, int> > g[1000001];
map<long long, int> last;
void update(int node, int l, int r, int ind, long long val) {
  if (l > r or l > ind or ind > r) return;
  if (l == r && l == ind) {
    st[node] = val;
    return;
  }
  update(2 * node, l, (l + r) >> 1, ind, val);
  update(2 * node + 1, ((l + r) >> 1) + 1, r, ind, val);
  st[node] = st[2 * node] ^ st[2 * node + 1];
}
long long query(int node, int l, int r, int ql, int qr) {
  if (l > r or ql > r or l > qr) return 0;
  if (qr >= r and l >= ql) return st[node];
  return query(2 * node, l, (l + r) / 2, ql, qr) ^
         query(2 * node + 1, (l + r) / 2 + 1, r, ql, qr);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  pre[0] = 0;
  for (int i = 1; i <= n; i++)
    scanf("%lld", &arr[i]), pre[i] = pre[i - 1] ^ arr[i];
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    g[b].push_back(make_pair(a, i));
  }
  for (int i = 1; i <= n; i++) {
    if (last[arr[i]]) update(1, 1, n, last[arr[i]], 0);
    last[arr[i]] = i;
    update(1, 1, n, i, arr[i]);
    for (auto it : g[i]) {
      ans[it.second] =
          query(1, 1, n, it.first, i) ^ (pre[i] ^ pre[it.first - 1]);
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
