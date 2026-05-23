#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50;
struct node {
  int x, r, q;
  int L, R;
  void print() { printf("%d %d %d %d %d\n", L, R, x, r, q); }
  bool operator<(const node& rhs) const { return r < rhs.r; }
} a[N];
struct Orz {
  vector<int> a;
  void clr() { a.clear(); }
  void add(int x) { a.push_back(x); }
  int siz() { return a.size(); }
  void work() {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
  }
  int idx(int x) { return lower_bound(a.begin(), a.end(), x) - a.begin() + 1; }
  int val(int i) { return a[i - 1]; }
} orz;
struct BIT {
  int c[N];
  int n;
  void init(int siz) { n = siz; }
  int lowbit(int x) { return x & (-x); }
  void add(int i, int x) {
    while (i <= n) {
      c[i] += x;
      i += lowbit(i);
    }
  }
  int sum(int i) {
    int ans = 0;
    while (i) {
      ans += c[i];
      i -= lowbit(i);
    }
    return ans;
  }
} bit;
int n, k;
long long ans;
bool cmp(node a, node b) { return a.q < b.q; }
void cdq(int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  cdq(l, mid);
  cdq(mid + 1, r);
  int p = mid + 1, q = mid + 1;
  for (int i = l; i <= mid; i++) {
    while (q <= r && a[q].q <= a[i].q + k) {
      bit.add(a[q].x, 1);
      q++;
    }
    while (p <= r && a[p].q < a[i].q - k) {
      bit.add(a[p].x, -1);
      p++;
    }
    ans += 1ll * (bit.sum(a[i].R) - bit.sum(a[i].L - 1));
  }
  for (int i = p; i < q; i++) {
    bit.add(a[i].x, -1);
  }
  inplace_merge(a + l, a + mid + 1, a + r + 1, cmp);
}
int main() {
  scanf("%d%d", &n, &k);
  orz.clr();
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q);
    orz.add(a[i].x);
    orz.add(a[i].x - a[i].r);
    orz.add(a[i].x + a[i].r);
  }
  orz.work();
  for (int i = 1; i <= n; i++) {
    int x = a[i].x;
    int r = a[i].r;
    a[i].x = orz.idx(x);
    a[i].L = orz.idx(x - r);
    a[i].R = orz.idx(x + r);
  }
  sort(a + 1, a + 1 + n);
  bit.init(orz.siz());
  cdq(1, n);
  printf("%lld\n", ans);
  return 0;
}
