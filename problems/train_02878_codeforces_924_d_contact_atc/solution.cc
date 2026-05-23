#include <bits/stdc++.h>
using namespace std;
int n, w;
long long ans;
struct plane {
  double a, b;
} p[100005], temp[100005];
int cmp(plane x, plane y) { return x.a < y.a || (x.a == y.a && x.b > y.b); }
void CDQ(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  CDQ(l, mid);
  CDQ(mid + 1, r);
  for (int i = l; i <= r; i++) temp[i] = p[i];
  int cnt = l;
  for (int i = l, j = mid + 1; i <= mid || j <= r;) {
    if ((j > r || temp[i].b < temp[j].b) && i <= mid)
      p[cnt++] = temp[i++];
    else
      p[cnt++] = temp[j++], ans += (long long)(mid - i + 1);
  }
}
int main() {
  scanf("%d %d", &n, &w);
  for (int i = 1, x, v; i <= n; i++) {
    scanf("%d %d", &x, &v);
    p[i].a = fabs((double)x / (double)(v + w));
    p[i].b = fabs((double)x / (double)(v - w));
  }
  sort(p + 1, p + 1 + n, cmp);
  CDQ(1, n);
  printf("%lld\n", ans);
  return 0;
}
