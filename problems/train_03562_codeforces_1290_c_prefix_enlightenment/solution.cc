#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 7;
using ll = long long;
string s;
int n, k;
int fa[maxn];
vector<int> st[maxn];
const int inf = 0x3f3f3f3f;
ll sz[maxn];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Union(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[y] = x;
    sz[x] += sz[y];
  }
}
int main() {
  for (int i = 0; i < maxn; ++i) fa[i] = i;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < k; ++i) {
    sz[i] = 1;
    int c;
    cin >> c;
    for (int j = 0, tmp; j < c; ++j) {
      cin >> tmp;
      --tmp;
      st[tmp].push_back(i);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (st[i].size() == 0)
      assert(s[i] == '1');
    else if (st[i].size() == 1) {
      int a1 = st[i][0];
      ans -= min(sz[find(a1)], sz[find(a1 + k)]);
      if (s[i] == '1')
        sz[find(a1)] += inf;
      else
        sz[find(a1 + k)] += inf;
      ans += min(sz[find(a1)], sz[find(a1 + k)]);
    } else {
      int u = st[i][0], v = st[i][1];
      ans -= min(sz[find(u)], sz[find(u + k)]);
      if (find(v) != find(u) && find(u) != find(v + k)) {
        ans -= min(sz[find(v)], sz[find(v + k)]);
      }
      if (s[i] == '0') {
        Union(u + k, v);
        Union(u, v + k);
      } else {
        Union(u, v);
        Union(u + k, v + k);
      }
      ans += min(sz[find(u)], sz[find(u + k)]);
      if (find(u) != find(v) && find(u) != find(v + k))
        ans += min(sz[find(v)], sz[find(v + k)]);
    }
    cout << ans << '\n';
  }
}
