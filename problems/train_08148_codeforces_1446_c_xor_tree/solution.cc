#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int size[6011100];
int l[6011100], r[6011100];
int id;
int ans;
int a[6011100];
void insert(int x) {
  int cur = 0;
  size[cur]++;
  for (int i = 29; i >= 0; --i) {
    if (l[cur] == -1) l[cur] = id++;
    if (r[cur] == -1) r[cur] = id++;
    cur = (1 << i) & x ? l[cur] : r[cur];
    size[cur]++;
    assert(id < 6011100);
  }
}
void dfs(int cur, int sum) {
  if (size[cur] == 2) {
    ans = max(ans, sum);
  }
  if (l[cur] >= 0) dfs(l[cur], sum + (size[r[cur]] > 0));
  if (r[cur] >= 0) dfs(r[cur], sum + (size[l[cur]] > 0));
}
int main() {
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  id = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    insert(a[i]);
  }
  ans = 0;
  dfs(0, 0);
  printf("%d\n", n - ans - 2);
}
