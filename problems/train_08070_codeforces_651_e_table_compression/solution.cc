#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f;
const double pi = acos(-1.0);
const double inf = 1e18;
const long long mod = 1e9 + 7;
const unsigned long long mx = 133333331;
inline void RI(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
int fa[1000005];
int a[1000005];
int b[1000005];
int n, m;
int deg[1000005];
int ans[1000005];
int get(int i, int j) { return i * m + j; }
bool cmp(int i, int j) { return a[i] < a[j]; }
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Union(int i, int j) { fa[Find(i)] = fa[Find(j)]; }
vector<int> v[1000005];
void add_edge(int a, int b) {
  v[b].push_back(a);
  deg[a]++;
}
int main() {
  cin >> n >> m;
  memset(deg, 0, sizeof(deg));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = get(i, j);
      scanf("%d", &a[x]);
      fa[x] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) b[j] = get(i, j);
    sort(b, b + m, cmp);
    int k;
    for (int j = 0; j < m; j = k) {
      for (k = j; k < m && a[b[j]] == a[b[k]]; k++) Union(b[j], b[k]);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) b[j] = get(j, i);
    sort(b, b + n, cmp);
    int k;
    for (int j = 0; j < n; j = k) {
      for (k = j; k < n && a[b[j]] == a[b[k]]; k++) Union(b[j], b[k]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) b[j] = get(i, j);
    sort(b, b + m, cmp);
    int k;
    for (int j = 1; j < m; j++)
      if (a[b[j]] > a[b[j - 1]]) add_edge(Find(b[j]), Find(b[j - 1]));
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) b[j] = get(j, i);
    sort(b, b + n, cmp);
    int k;
    for (int j = 1; j < n; j++)
      if (a[b[j]] > a[b[j - 1]]) add_edge(Find(b[j]), Find(b[j - 1]));
  }
  queue<int> q;
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n * m; i++) {
    if (fa[i] == i && !deg[i]) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans[u]++;
    for (int i = 0; i < v[u].size(); i++) {
      int vv = v[u][i];
      deg[vv]--;
      ans[vv] = max(ans[vv], ans[u]);
      if (!deg[vv] && fa[vv] == vv) {
        q.push(vv);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", ans[Find(get(i, j))]);
      if (j == m - 1)
        printf("\n");
      else
        printf(" ");
    }
  }
  return 0;
}
