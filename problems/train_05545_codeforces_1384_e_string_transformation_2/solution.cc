#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int base = 31337;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;
int t;
int n;
char a[maxn], b[maxn];
int graph[100], graph2[100];
bool dp[treesiz];
bool bio[100];
vector<int> v;
void dfs(int x) {
  bio[x] = true;
  v.push_back(x);
  for (int i = 0; i < 20; i++) {
    if ((graph2[x] & (1 << i)) && !bio[i]) dfs(i);
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof dp);
    memset(graph, 0, sizeof graph);
    memset(graph2, 0, sizeof graph2);
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        int x = a[i] - 'a';
        int y = b[i] - 'a';
        graph[x] |= (1 << y);
        graph2[x] |= (1 << y);
        graph2[y] |= (1 << x);
      }
    }
    memset(dp, false, sizeof dp);
    dp[0] = true;
    for (int mask = 1; mask < off; mask++) {
      for (int i = 0; i < 20; i++) {
        if ((mask & (1 << i)) == 0) continue;
        if (dp[mask ^ (1 << i)] && (mask & graph[i]) == 0) dp[mask] = true;
      }
    }
    memset(bio, false, sizeof bio);
    int sol = 0;
    for (int i = 0; i < 20; i++) {
      if (!bio[i]) {
        dfs(i);
        int maxi = 0;
        int pc = (1 << v.size());
        for (int mask = 0; mask < pc; mask++) {
          int pmask = 0, cnt = 0;
          for (int j = 0; j < v.size(); j++) {
            if (mask & (1 << j)) pmask |= (1 << v[j]), cnt++;
          }
          if (dp[pmask]) maxi = max(maxi, cnt);
        }
        sol += 2 * v.size() - maxi - 1;
        v.clear();
      }
    }
    printf("%d\n", sol);
  }
  return 0;
}
