#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 1;
static vector<vector<int>> vert(MAXN, vector<int>(0));
static int outdeg[MAXN];
static int indeg[MAXN];
int n, m;
long long ans = 0;
static void solveShit() {
  int v;
  scanf("%d", &v);
  ans -= (long long)indeg[v] * (long long)outdeg[v];
  for (int son : vert[v]) {
    ans -= (long long)indeg[son];
    ans += (long long)(outdeg[son] - 1);
    indeg[v]--;
    outdeg[v]++;
    indeg[son]++;
    outdeg[son]--;
    vert[son].push_back(v);
  }
  vert[v].clear();
  printf("%lld\n", ans);
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    vert[min(a, b)].push_back(max(a, b));
    indeg[min(a, b)]++;
    outdeg[max(a, b)]++;
  }
  for (int i = 1; i < n + 1; i++) {
    ans += (long long)indeg[i] * (long long)outdeg[i];
  }
  printf("%lld\n", ans);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    solveShit();
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
