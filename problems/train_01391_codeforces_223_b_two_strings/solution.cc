#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char a[N], b[N];
int last[26];
vector<int> G[26];
bool vis[N];
int lc[N], rc[N];
int main() {
  cin >> a >> b;
  int m = strlen(b);
  for (int i = 0; i < m; i++) G[b[i] - 'a'].push_back(i);
  memset(last, -1, sizeof(last));
  int n = strlen(a);
  for (int i = 0; i < n; i++) {
    int x = a[i] - 'a';
    lc[i] = last[x];
    int p = last[x] + 1;
    if (p == G[x].size()) continue;
    int pos = G[x][p];
    if (0 == pos || vis[pos - 1]) {
      lc[i] = ++last[x];
      vis[pos] = 1;
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 26; i++) last[i] = G[i].size();
  for (int i = n - 1; i >= 0; i--) {
    int x = a[i] - 'a';
    rc[i] = last[x];
    int p = last[x] - 1;
    if (p == -1) continue;
    int pos = G[x][p];
    if (pos + 1 == m || vis[pos + 1]) {
      rc[i] = --last[x];
      vis[pos] = 1;
    }
  }
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    if (lc[i] < rc[i]) flag = 0;
  }
  puts(flag ? "Yes" : "No");
}
