#include <bits/stdc++.h>
using namespace std;
int n, m, q, nn;
int fa[400100];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int ans;
void unionn(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  fa[x] = y;
  nn--;
}
int main() {
  int i, a, b;
  for (i = 1; i <= 400000; i++) fa[i] = i;
  scanf("%d%d%d", &n, &m, &q);
  nn = n + m;
  for (i = 1; i <= q; i++) {
    scanf("%d%d", &a, &b);
    unionn(a, b + n);
  }
  printf("%d", nn - 1);
  return 0;
}
