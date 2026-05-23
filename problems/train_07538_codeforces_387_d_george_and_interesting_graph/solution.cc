#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int maxn = 2021;
const int maxm = 50020;
int n, m, Ans, tot, S, T;
int A[maxn], B[maxn], head[maxn], deep[maxn], in[maxn], out[maxn];
struct node {
  int to, net, va;
} data[maxm << 2];
queue<int> q;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
void add(int a, int b, int c) {
  data[++tot].net = head[a];
  data[tot].to = b;
  data[tot].va = c;
  head[a] = tot;
  data[++tot].net = head[b];
  data[tot].to = a;
  data[tot].va = 0;
  head[b] = tot;
}
bool bfs() {
  memset(deep, 0, sizeof(deep));
  while (!q.empty()) q.pop();
  deep[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = data[i].net) {
      int to = data[i].to, va = data[i].va;
      if (va && !deep[to]) {
        deep[to] = deep[x] + 1;
        if (to == T)
          return true;
        else
          q.push(to);
      }
    }
  }
  return false;
}
int dinic(int x, int flow) {
  if (x == T) return flow;
  int rest = flow;
  for (int i = head[x]; i != -1; i = data[i].net) {
    int to = data[i].to, va = data[i].va;
    if (deep[to] == deep[x] + 1 && va) {
      int k = dinic(to, min(va, rest));
      if (!k) deep[to] = 0;
      data[i].va -= k;
      data[i ^ 1].va += k;
      rest -= k;
    }
    if (!rest) return flow;
  }
  return flow - rest;
}
int solve(int x) {
  memset(head, -1, sizeof(head));
  tot = -1;
  for (int i = 1; i <= n; i++) add(S, i, 1), add(i + n, T, 1);
  for (int i = 1; i <= m; i++)
    if (A[i] != x && B[i] != x) add(A[i], B[i] + n, 1);
  int ans = 0;
  while (bfs()) ans += dinic(S, inf);
  return n - 1 - ans + m - ans - in[x] - out[x] + 2 * n - 1 - in[x] - out[x];
}
int main() {
  n = read();
  m = read();
  Ans = inf;
  S = 2 * n + 1;
  T = 2 * n + 2;
  for (int i = 1; i <= m; i++) {
    A[i] = read();
    B[i] = read();
    in[B[i]]++;
    out[A[i]]++;
    in[B[i]] -= A[i] == B[i];
  }
  for (int i = 1; i <= n; i++) Ans = min(Ans, solve(i));
  printf("%d\n", Ans);
  return 0;
}
