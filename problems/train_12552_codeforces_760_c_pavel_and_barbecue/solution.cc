#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
vector<int> vec[200005];
bool vis[200005];
void dfs(int node) {
  vis[node] = true;
  for (int i = 0; i < vec[node].size(); i++) {
    int Node = vec[node][i];
    if (!vis[Node]) {
      dfs(Node);
    }
  }
}
int main() {
  int n, ans, cnt, v;
  ans = cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v);
    vec[i].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v);
    if (v) cnt++;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      ans++;
    }
  }
  if (ans == 1) ans = 0;
  ans += (cnt & 1 ? 0 : 1);
  printf("%d\n", ans);
  return 0;
}
