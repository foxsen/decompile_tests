#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int v[5], w[5], id[5];
long long p1[N], p2[N];
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
namespace N1 {
int sum;
void insert(int x, int fl) {
  if (!p1[x] && !p2[x]) fl ? ++sum : --sum;
}
bool check() { return sum != 0; }
}  // namespace N1
namespace N2 {
map<pair<long long, long long>, int> mp;
int sum;
void insert(int x, int fl) {
  if (fl == 1) {
    if (!mp[pair<long long, long long>(p1[x], p2[x])])
      if (mp[pair<long long, long long>(-p1[x], -p2[x])]) ++sum;
    ++mp[pair<long long, long long>(p1[x], p2[x])];
  } else {
    --mp[pair<long long, long long>(p1[x], p2[x])];
    if (!mp[pair<long long, long long>(p1[x], p2[x])])
      if (mp[pair<long long, long long>(-p1[x], -p2[x])]) --sum;
  }
}
bool check() { return sum != 0; }
}  // namespace N2
namespace N3 {
int mn[N * 4];
int mx[N * 4];
int fl[N * 4];
int cmp(int x, int y) {
  double v = 1.0 * p1[x] * p2[y] - 1.0 * p1[y] * p2[x];
  if (fabs(v) > 1e12) return v > 0 ? 1 : -1;
  long long vv = p1[x] * p2[y] - p1[y] * p2[x];
  return (vv ? (vv > 0 ? 1 : -1) : 0);
}
void pushup(int k) {
  int ls = k * 2, rs = k * 2 + 1;
  fl[k] = fl[ls] | fl[rs];
  if (!mn[ls] || !mn[rs]) {
    mn[k] = mn[ls] + mn[rs];
    mx[k] = mx[ls] + mx[rs];
  } else {
    if (cmp(mn[ls], mn[rs]) == -1 && cmp(mn[ls], mx[rs]) == 1) fl[k] = 1;
    if (cmp(mn[rs], mn[ls]) == -1 && cmp(mn[rs], mx[ls]) == 1) fl[k] = 1;
    if (cmp(mx[ls], mn[rs]) == -1 && cmp(mx[ls], mx[rs]) == 1) fl[k] = 1;
    if (cmp(mx[rs], mn[ls]) == -1 && cmp(mx[rs], mx[ls]) == 1) fl[k] = 1;
    mn[k] = (cmp(mn[ls], mn[rs]) == -1 ? mn[ls] : mn[rs]);
    mx[k] = (cmp(mx[ls], mx[rs]) == -1 ? mx[rs] : mx[ls]);
  }
}
void insert(int k, int l, int r, int x, int v) {
  if (l == r) {
    mn[k] = mx[k] = v * x;
    fl[k] = 0;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    insert(k * 2, l, mid, x, v);
  else
    insert(k * 2 + 1, mid + 1, r, x, v);
  pushup(k);
}
void insert(int x, int v) { insert(1, 1, N - 1, x, v); }
bool check() { return fl[1]; }
}  // namespace N3
int main() {
  scanf("%d%d%d", &v[1], &v[2], &v[3]);
  id[1] = 1;
  id[2] = 2;
  id[3] = 3;
  if (!v[id[1]]) swap(id[1], id[2]);
  if (!v[id[1]]) swap(id[1], id[3]);
  int Q, n = 0;
  scanf("%d", &Q);
  while (Q--) {
    char s[10];
    scanf("%s", s + 1);
    if (s[1] == 'A') {
      scanf("%d%d%d", &w[1], &w[2], &w[3]);
      ++n;
      p1[n] = 1ll * w[id[2]] * v[id[1]] - 1ll * v[id[2]] * w[id[1]];
      p2[n] = 1ll * w[id[3]] * v[id[1]] - 1ll * v[id[3]] * w[id[1]];
      long long G = gcd(abs(p1[n]), abs(p2[n]));
      if (G) p1[n] /= G, p2[n] /= G;
      N1::insert(n, 1);
      N2::insert(n, 1);
      N3::insert(n, 1);
    } else {
      int x;
      scanf("%d", &x);
      N1::insert(x, 0);
      N2::insert(x, 0);
      N3::insert(x, 0);
    }
    if (N1::check())
      puts("1");
    else if (N2::check())
      puts("2");
    else if (N3::check())
      puts("3");
    else
      puts("0");
  }
}
