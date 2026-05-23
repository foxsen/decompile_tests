#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
using namespace std;
bool vis[5000000];
bool have[5000000];
int a[5000000];
int N, M, MASK;
void dfs(int u) {
  vis[u] = 1;
  if (!vis[u ^ MASK] && have[u]) dfs(u ^ MASK);
  for (int i = 0; i < N; i++) {
    if (u & (1 << i)) {
      if (!vis[u ^ (1 << i)]) dfs(u ^ (1 << i));
    }
  }
}
int main() {
  scanf("%d%d", &N, &M);
  MASK = (1 << N) - 1;
  for (int i = 0; i < M; i++) {
    scanf("%d", &a[i]);
    have[a[i]] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    if (!vis[a[i]]) {
      cnt++;
      dfs(a[i]);
    }
  }
  cout << cnt << endl;
  return 0;
}
