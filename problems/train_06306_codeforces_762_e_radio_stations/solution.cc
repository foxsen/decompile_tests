#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> v[N];
int n, k, b[N], rot[N], tot;
long long ans;
int lson[N * 20], rson[N * 20], s[N * 20];
struct node {
  int xi, ri, fi;
} a[N];
bool cmp(node A, node B) { return A.ri > B.ri; }
int lp(int x) { return lower_bound(b + 1, b + 1 + n, x) - b; }
int up(int x) { return upper_bound(b + 1, b + 1 + n, x) - b; }
void ins(int &rt, int l, int r, int x) {
  if (!rt) rt = ++tot;
  s[rt]++;
  int mid = l + r >> 1;
  if (l == r) return;
  if (x <= mid)
    ins(lson[rt], l, mid, x);
  else
    ins(rson[rt], mid + 1, r, x);
}
int query(int rt, int l, int r, int x, int y) {
  if (!rt) return 0;
  if (x <= l && r <= y) return s[rt];
  int mid = l + r >> 1, t = 0;
  if (x <= mid) t += query(lson[rt], l, mid, x, y);
  if (mid < y) t += query(rson[rt], mid + 1, r, x, y);
  return t;
}
signed main() {
  scanf("%d %d", &n, &k);
  for (register int i = (1); i <= (n); ++i)
    scanf("%d %d %d", &a[i].xi, &a[i].ri, &a[i].fi), b[i] = a[i].xi;
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + n);
  for (register int i = (1); i <= (n); ++i) {
    int x = lp(a[i].xi - a[i].ri), y = up(a[i].xi + a[i].ri) - 1;
    y = min(y, n);
    for (register int j = (a[i].fi - k); j <= (a[i].fi + k); ++j)
      if (j >= 1) ans += query(rot[j], 1, n, x, y);
    ins(rot[a[i].fi], 1, n, lp(a[i].xi));
  }
  printf("%lld\n", ans);
  return 0;
}
