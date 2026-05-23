#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
int cnt, u[400010], v[400010], last1[200010], last2[200010], nxt[400010];
long long w[400010], d1[200010], d2[200010];
unsigned long long f1[400010], f2[400010];
void insert(int x, int y, int z) {
  u[++cnt] = x;
  v[cnt] = y;
  w[cnt] = (long long)z;
  nxt[cnt] = last1[x];
  last1[x] = cnt;
  u[cnt + m] = y;
  v[cnt + m] = x;
  w[cnt + m] = (long long)z;
  nxt[cnt + m] = last2[y];
  last2[y] = cnt + m;
}
struct node {
  long long dis;
  int p;
  bool operator<(node x) const { return dis > x.dis; }
  node(){};
  node(long long d, int id) {
    dis = d;
    p = id;
  }
};
priority_queue<node> q;
int vis[200010];
void dijkstra(int s, long long d[], unsigned long long f[], int head[]) {
  int i, j, k;
  node a;
  for (i = 1; i <= n; i++) d[i] = 1e15;
  for (i = 1; i <= n; i++) vis[i] = 0;
  d[s] = 0;
  f[s] = 1;
  while (!q.empty()) q.pop();
  q.push(node(0, s));
  while (!q.empty()) {
    a = q.top();
    q.pop();
    if (vis[a.p]) continue;
    vis[a.p] = 1;
    for (i = head[a.p]; i; i = nxt[i])
      if (d[v[i]] > a.dis + w[i]) {
        d[v[i]] = a.dis + w[i];
        f[v[i]] = f[a.p];
        q.push(node(d[v[i]], v[i]));
      } else if (d[v[i]] == a.dis + w[i])
        f[v[i]] = (f[v[i]] + f[a.p]) % (long long)(9875321);
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    insert(a, b, c);
  }
  dijkstra(s, d1, f1, last1);
  dijkstra(t, d2, f2, last2);
  long long ans1;
  unsigned long long ans2;
  for (int i = 1; i <= m; i++) {
    ans1 = d1[u[i]] + d2[v[i]];
    ans2 = f1[u[i]] * f2[v[i]] % (long long)(9875321);
    if (ans1 + w[i] == d1[t] && ans2 == f1[t])
      printf("YES\n");
    else if (ans1 + 1 < d1[t])
      printf("CAN %I64d\n", w[i] + ans1 + 1 - d1[t]);
    else
      printf("NO\n");
  }
  return 0;
}
