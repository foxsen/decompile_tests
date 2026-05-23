#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::max;
using std::min;
int n, m, K, a, b, ecnt, last[500005], A[500005], Bn, f[500005 << 1],
    size[500005 << 1], mark[500005], sta[500005 << 1], top, tot;
long long ans;
struct node {
  int x, y;
} B[500005];
struct road {
  int to, nex;
} e[500005];
void adde(int u, int v) { e[++ecnt] = {v, last[u]}, last[u] = ecnt; }
int find(int x) { return f[x] ^ x ? find(f[x]) : x; }
bool merge(int x, int y) {
  int f1 = find(x), f2 = find(y);
  if (f1 ^ f2) {
    if (size[f1] > size[f2]) std::swap(f1, f2);
    f[f1] = f2, size[f2] += size[f1], sta[++top] = f1;
  }
  return find(x) == find(x + n);
}
void Solve(int l, int r) {
  if (mark[A[B[l].x]] || mark[A[B[l].y]]) return;
  int flag = 0;
  for (int i = l; i <= r && !flag; i++)
    a = B[i].x, b = B[i].y, flag |= merge(a, b + n) | merge(b, a + n);
  if (flag) ans++;
  for (int x; top;) x = sta[top--], size[f[x]] -= size[x], f[x] = x;
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= n << 1; i++) f[i] = i, size[i] = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    if (A[a] ^ A[b]) {
      if (A[a] > A[b]) std::swap(a, b);
      B[++Bn] = {a, b};
    } else
      mark[A[a]] |= merge(a, b + n) | merge(b, a + n);
  }
  for (int i = 1; i <= K; i++) tot += mark[i];
  ans = (long long)tot * (K - tot) + (long long)tot * (tot - 1) / 2, top = 0;
  std::sort(B + 1, B + 1 + Bn, [](node t1, node t2) {
    return A[t1.x] < A[t2.x] || A[t1.x] == A[t2.x] && A[t1.y] < A[t2.y];
  });
  for (int i = 1, j = 1; i <= Bn; i++)
    if (A[B[i].x] ^ A[B[i + 1].x] || A[B[i].y] ^ A[B[i + 1].y] || i == Bn)
      Solve(j, i), j = i + 1;
  printf("%lld\n", (long long)K * (K - 1) / 2 - ans);
  return 0;
}
