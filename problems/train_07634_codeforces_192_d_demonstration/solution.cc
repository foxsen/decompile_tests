#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
long long money;
int a[N];
int aux[N], size[N], key[N], lc[N], rc[N], top, root;
long long sum[N];
void l_rotate(int &x) {
  int y = rc[x];
  rc[x] = lc[y];
  lc[y] = x;
  size[y] = size[x];
  size[x] = size[lc[x]] + size[rc[x]] + 1;
  sum[y] = sum[x];
  sum[x] = sum[lc[x]] + sum[rc[x]] + key[x];
  x = y;
}
void r_rotate(int &x) {
  int y = lc[x];
  lc[x] = rc[y];
  rc[y] = x;
  size[y] = size[x];
  size[x] = size[lc[x]] + size[rc[x]] + 1;
  sum[y] = sum[x];
  sum[x] = sum[lc[x]] + sum[rc[x]] + key[x];
  x = y;
}
void insert(int &k, int x) {
  if (!k) {
    k = ++top;
    aux[k] = rand();
    size[k] = 1;
    sum[k] = key[k] = x;
    return;
  }
  ++size[k];
  sum[k] += x;
  if (x <= key[k]) {
    insert(lc[k], x);
    if (aux[lc[k]] < aux[k]) r_rotate(k);
  } else {
    insert(rc[k], x);
    if (aux[rc[k]] < aux[k]) l_rotate(k);
  }
}
long long calcSum(int k) {
  long long ret = 0;
  int now = root;
  while (now)
    if (size[rc[now]] + 1 <= k)
      ret += sum[rc[now]] + key[now], k -= size[rc[now]] + 1, now = lc[now];
    else
      now = rc[now];
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  cin >> money;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  int ans = n;
  for (int i = 1; i < m; ++i) insert(root, a[n - i]);
  for (int i = n - m; i; --i) {
    if (money < calcSum(m - 1) + a[i]) ans = i;
    insert(root, a[i]);
  }
  printf("%d\n", ans);
}
