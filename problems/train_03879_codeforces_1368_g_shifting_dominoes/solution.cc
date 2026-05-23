#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
int n, m;
char s[M];
long long Ans = 0;
vector<char> Map[M];
int Num(int x, int y) { return (x - 1) * m + y; }
int cnt = 0, gp[M][2], To[M];
vector<int> G[M];
bool notr[M];
void add(int x0, int y0, int x1, int y1) {
  G[Num(x0, y0)].push_back(Num(x1, y1));
  notr[Num(x1, y1)] = 1;
}
int num = 0, L[M], R[M];
void dfs(int u) {
  L[u] = ++num;
  for (int v : G[u]) dfs(v);
  R[u] = num;
}
int sum[M << 2], lazy[M << 2];
void pushup(int u, int l, int r) {
  if (lazy[u])
    sum[u] = r - l + 1;
  else if (l < r)
    sum[u] = sum[u << 1] + sum[u << 1 | 1];
  else
    sum[u] = 0;
}
void Change(int u, int l, int r, int L, int R, int x) {
  if (L > r || R < l) return;
  if (L <= l && r <= R) return (void)(lazy[u] += x, pushup(u, l, r));
  int mid = (l + r) >> 1;
  Change(u << 1, l, mid, L, R, x), Change(u << 1 | 1, mid + 1, r, L, R, x);
  pushup(u, l, r);
}
int idx = 0;
struct Line {
  int l, r, y, zf;
} li[M];
bool cmp(Line x, Line y) { return x.y > y.y; }
void Add(int x0, int y0, int x1, int y1) {
  li[++idx] = (Line){x0, x1, y1, 1};
  li[++idx] = (Line){x0, x1, y0 - 1, -1};
}
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    Map[i].push_back('#');
    for (int j = 1; j <= m; j++) Map[i].push_back(s[j]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i + 2 <= n && Map[i + 1][j] == 'U' && Map[i + 2][j] == 'D')
        add(i, j, i + 2, j);
      if (i - 2 >= 1 && Map[i - 1][j] == 'D' && Map[i - 2][j] == 'U')
        add(i, j, i - 2, j);
      if (j + 2 <= m && Map[i][j + 1] == 'L' && Map[i][j + 2] == 'R')
        add(i, j, i, j + 2);
      if (j - 2 >= 1 && Map[i][j - 1] == 'R' && Map[i][j - 2] == 'L')
        add(i, j, i, j - 2);
      if (!To[Num(i, j)]) {
        To[Num(i, j)] = ++cnt;
        gp[cnt][0] = Num(i, j);
        if (Map[i][j] == 'L')
          To[Num(i, j + 1)] = cnt, gp[cnt][1] = Num(i, j + 1);
        if (Map[i][j] == 'U')
          To[Num(i + 1, j)] = cnt, gp[cnt][1] = Num(i + 1, j);
        if ((i + j) & 1) swap(gp[cnt][0], gp[cnt][1]);
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!notr[Num(i, j)]) dfs(Num(i, j));
  for (int i = 1; i <= cnt; i++) {
    int x0 = L[gp[i][0]], x1 = R[gp[i][0]];
    int y0 = L[gp[i][1]], y1 = R[gp[i][1]];
    Add(x0, y0, x1, y1);
  }
  sort(li + 1, li + idx + 1, cmp);
  for (int i = 1; i < idx; i++) {
    Change(1, 1, n * m, li[i].l, li[i].r, li[i].zf);
    Ans += 1ll * (li[i].y - li[i + 1].y) * sum[1];
  }
  printf("%lld\n", Ans);
}
signed main() { solve(); }
