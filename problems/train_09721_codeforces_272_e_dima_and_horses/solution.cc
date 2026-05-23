#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
bool res[maxn];
struct Edge {
  int next;
  int to;
} edge[2 * maxn];
int r[maxn];
int head[2 * maxn], tot;
inline void add(int from, int to) {
  edge[++tot].next = head[from];
  edge[tot].to = to;
  head[from] = tot;
}
void init() { memset(head, -1, sizeof(head)); }
void dfs(int idx) {
  int sum = 0;
  for (int i = head[idx]; ~i; i = edge[i].next) {
    int y = edge[i].to;
    if (res[idx] == res[y]) sum++;
  }
  if (sum > 1) {
    res[idx] = !res[idx];
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  init();
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    add(a, b), add(b, a);
    r[a]++, r[b]++;
  }
  for (int k = 1; k <= 20; ++k)
    for (int i = 1; i <= n; ++i) {
      dfs(i);
    }
  for (int i = 1; i <= n; ++i) cout << res[i];
}
