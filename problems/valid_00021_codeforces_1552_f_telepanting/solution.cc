#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 998244353;
struct wocao {
  int x, y, s;
} a[200020];
int aa[400040];
map<int, int> mp;
int bb[400040];
int c[400040];
int lowbit(int x) { return x & (-x); }
int query(int x) {
  int ret = 0;
  while (x) (ret += c[x]) %= mod, x -= lowbit(x);
  return ret;
}
void add(int x, int y) {
  while (x <= n * 2) (c[x] += y) %= mod, x += lowbit(x);
}
int t[400040];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].s), aa[i * 2 - 1] = a[i].x,
                                                           aa[i * 2] = a[i].y;
  sort(aa + 1, aa + n * 2 + 1);
  int tttt = 0;
  for (int i = 1; i <= 2 * n; i++)
    if (aa[i] != aa[i - 1]) mp[aa[i]] = ++tttt, bb[tttt] = aa[i];
  for (int i = 1; i <= n; i++) a[i].x = mp[a[i].x], a[i].y = mp[a[i].y];
  int temp;
  for (int i = n; i >= 1; i--) {
    if (a[i].s == 1) {
      t[i] = (query(a[i].x) + 1) % mod;
    } else {
      t[i] = query(a[i].x);
    }
    add(a[i].y, t[i]);
  }
  int ans = (bb[a[n].x] + 1) % mod;
  for (int i = 1; i <= n; i++) {
    long long l = bb[a[i].x] - bb[a[i].y];
    (l *= t[i]) %= mod;
    (ans += l) %= mod;
  }
  cout << ans;
  return 0;
}
