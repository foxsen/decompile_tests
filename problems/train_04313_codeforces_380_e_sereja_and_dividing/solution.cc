#include <bits/stdc++.h>
using namespace std;
const int T = 60, maxn = 3e5 + 5;
struct node {
  int id, val;
} a[maxn];
int n;
int pre[maxn], nxt[maxn];
bool cmp(node a, node b) {
  return a.val == b.val ? a.id < b.id : a.val < b.val;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    nxt[i] = i + 1, pre[i] = i - 1;
  }
  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    int x = a[i].id;
    int L = x, R = x;
    double l = 0, r = 0, div = 1;
    for (int j = 1; j <= T; j++) {
      div *= .5;
      if (L) {
        l += div * (L - pre[L]);
        L = pre[L];
      }
      if (R <= n) {
        r += div * (nxt[R] - R);
        R = nxt[R];
      }
    }
    ans += 2 * a[i].val * l * r;
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
  }
  printf("%f\n", ans / n / n);
  return 0;
}
