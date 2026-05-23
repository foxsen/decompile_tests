#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans;
int a[1000000];
int tree[1000000];
int b[50] = {
    0,    4,    7,    44,   47,   74,   77,   444,  447,  474,  477,
    744,  747,  774,  777,  4444, 4447, 4474, 4477, 4744, 4747, 4774,
    4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777,
};
int f[1000000];
void pushup(int id) { tree[id] = tree[id * 2] + tree[id * 2 + 1]; }
void Update(int id, int le, int ri, int x, int k) {
  if (le == ri) {
    tree[id] += k;
    return;
  }
  int mid = (le + ri) / 2;
  if (x <= mid)
    Update(id * 2, le, mid, x, k);
  else
    Update(id * 2 + 1, mid + 1, ri, x, k);
  pushup(id);
}
int query(int id, int le, int ri, int ll, int rr) {
  if (ll <= le && ri <= rr) return tree[id];
  int mid = (le + ri) / 2, k = 0;
  if (ll <= mid) k += query(id * 2, le, mid, ll, rr);
  if (rr > mid) k += query(id * 2 + 1, mid + 1, ri, ll, rr);
  return k;
}
int main() {
  int i, n, m;
  scanf("%d%d", &n, &m);
  memset(f, 0, sizeof(f));
  for (i = 1; i <= 50; i++) f[b[i]] = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (f[a[i]]) Update(1, 1, n, i, 1);
  }
  while (m--) {
    char ch[100];
    scanf("%s", &ch);
    int x, y, z;
    scanf("%d%d", &x, &y);
    if (!strcmp(ch, "add")) {
      scanf("%d", &z);
      for (int i = x; i <= y; i++) {
        int k = 0;
        if (f[a[i]]) k--;
        a[i] += z;
        if (f[a[i]]) k++;
        if (k) Update(1, 1, n, i, k);
      }
    } else
      printf("%d\n", query(1, 1, n, x, y));
  }
  return 0;
}
