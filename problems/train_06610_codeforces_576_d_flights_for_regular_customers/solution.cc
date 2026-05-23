#include <bits/stdc++.h>
using namespace std;
int n, m;
int dis[10010];
struct M {
  bitset<210> s[210];
} Ye;
bitset<210> ans;
struct edge {
  int a, b, v;
} e[1010];
M operator*(const M &x, const M &y) {
  M now;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (x.s[i][j]) now.s[i] |= y.s[j];
  return now;
}
bitset<210> operator*(const bitset<210> &x, const M &y) {
  bitset<210> now;
  for (int i = 0; i < n; i++) now[i] = (x & y.s[i]).any();
  return now;
}
M ksm(M a, long long b) {
  M ans = a;
  b--;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
bool cmp(edge a, edge b) { return a.v < b.v; }
int bfs() {
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (ans[i])
      q.push(i), dis[i] = 0;
    else
      dis[i] = 0x3f3f3f3f;
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (Ye.s[i][now] && dis[i] == 0x3f3f3f3f)
        dis[i] = dis[now] + 1, q.push(i);
    }
  }
  return dis[n - 1];
}
int main() {
  scanf("%d%d", &n, &m);
  ans[0] = 1;
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].v);
  sort(e + 1, e + m + 1, cmp);
  if (e[1].v != 0) {
    printf("Impossible");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    Ye.s[e[i].b - 1][e[i].a - 1] = 1;
    int last = e[i].v;
    while (e[i + 1].v == last && i + 1 <= m)
      i++, Ye.s[e[i].b - 1][e[i].a - 1] = 1;
    int cnt;
    if (i < m)
      cnt = e[i + 1].v - e[i].v;
    else
      cnt = 1;
    bitset<210> ans1 = ans * ksm(Ye, cnt);
    int nowans;
    if ((nowans = bfs()) != 0x3f3f3f3f) {
      printf("%d", last + nowans);
      return 0;
    } else {
      bool f = 0;
      for (int i = 0; i < n; i++)
        if (ans1[i]) f = 1;
      if (!f) {
        printf("Impossible");
        return 0;
      }
    }
    ans = ans1;
  }
  fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, 88);
  printf("Impossible");
}
