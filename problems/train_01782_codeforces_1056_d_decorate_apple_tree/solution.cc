#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int a[100010];
int dfs(int x) {
  int ans = 1;
  for (auto i : v[x]) a[i] = dfs(i), ans += a[i];
  if (ans != 1) ans--;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (register int i = (2); i <= (n); i++) {
    int x;
    scanf("%d", &x);
    v[x].push_back(i);
  }
  a[1] = dfs(1);
  sort(a + 1, a + 1 + n);
  for (register int i = (1); i <= (n); i++) printf("%d%c", a[i], ' ');
}
