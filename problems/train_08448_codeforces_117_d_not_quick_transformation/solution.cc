#include <bits/stdc++.h>
using namespace std;
const int H = 1000000;
template <typename Key, typename Val>
struct Hash {
  char *used;
  Key *key;
  Val *val;
  Hash() {
    used = new char[H];
    key = new Key[H];
    val = new Val[H];
    memset(used, 0, sizeof(used));
  }
  int hash_func(const Key &k) { return k % H; }
  pair<bool, int> find(const Key &k) {
    int h = hash_func(k);
    for (;; h++, h = (h == H) ? 0 : h) {
      if (not used[h]) return make_pair(false, h);
      if (key[h] == k) return make_pair(true, h);
    }
  }
  void insert(const Key &k, const Val &v) {
    int h = find(k).second;
    used[h] = 1;
    key[h] = k;
    val[h] = v;
  }
  Val &get(const Key &k) {
    pair<bool, int> f = find(k);
    if (!f.first) assert(false);
    return val[f.second];
  }
};
int mod;
long long find(const long long &n, long long l, long long r, long long u,
               long long v, long long &num) {
  num = 0;
  if (l > r or u > v) return 0;
  if (v < 1 or n < u) return 0;
  if (r < 1 or n < l) return 0;
  if (n == 1) {
    if (l <= 1 and 1 <= r and u <= 1 and 1 <= v) {
      num = 1;
      return 1;
    } else {
      num = 0;
      return 0;
    }
  }
  l = max(1ll, l);
  r = min(n, r);
  u = max(1ll, u);
  v = min(n, v);
  if (l == 1 and r == n) {
    num = v - u + 1;
    long long c1 = v + u, c2 = (v - u + 1);
    if (c1 % 2 == 0)
      c1 /= 2;
    else
      c2 /= 2;
    c1 %= mod;
    c2 %= mod;
    return c1 * c2 % mod;
    ;
  }
  num = 0;
  const long long n1 = (n + 1) / 2, n2 = n / 2;
  long long ans = 0;
  if (l <= n1) {
    long long u1 = u, v1 = v, nn;
    if (u1 % 2 == 0) u1++;
    if (v1 % 2 == 0) v1--;
    ans += find(n1, l, min(r, n1), (u1 + 1) / 2, (v1 + 1) / 2, nn) * 2;
    num += nn;
    ans -= nn;
  }
  if (n1 + 1 <= r) {
    long long u1 = u, v1 = v, nn;
    if (u1 % 2 == 1) u1++;
    if (v1 % 2 == 1) v1--;
    ans += find(n2, max(l, n1 + 1) - n1, r - n1, u1 / 2, v1 / 2, nn) * 2;
    num += nn;
  }
  ans = (ans % mod + mod) % mod;
  return ans;
}
long long n;
int m;
long long l, r, u, v;
int main() {
  scanf("%I64d%d%d", &n, &m, &mod);
  for (int i = 0; i < (int)(m); ++i) {
    scanf("%I64d%I64d%I64d%I64d", &l, &r, &u, &v);
    long long n1;
    printf("%lld\n", find(n, l, r, u, v, n1));
  }
  return 0;
}
