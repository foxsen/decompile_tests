#include <bits/stdc++.h>
using namespace std;
struct Tire {
  int b, size, son[2], num[31];
} t[51000 * 31];
int a[51000], n, tot = 1, ans, F;
long long m;
int Get(int i, int w) { return ((i & (1 << w))) ? true : false; }
void Insert(int a) {
  int x = 1;
  for (int i = 30; i >= 0; i--) {
    t[x].size++;
    for (int j = 0; j <= 30; j++)
      if (a & (1 << j)) t[x].num[j]++;
    int k = Get(a, i);
    if (t[x].son[k])
      x = t[x].son[k];
    else
      t[++tot].b = (t[x].b << 1) + k, t[x].son[k] = tot, x = tot;
  }
  t[x].size++;
  for (int j = 0; j <= 30; j++)
    if (a & (1 << j)) t[x].num[j]++;
}
int power(long long a, int b) {
  long long d = 1;
  for (; b > 1;
       d = (b & 1) ? (d * a % 1000000007) : d, a = a * a % 1000000007, b /= 2)
    ;
  return (int)(a * d % 1000000007);
}
void init() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), Insert(a[i]);
  F = power(2LL, 1000000007 - 2);
}
int go(int pre, int w) {
  int x = 1;
  for (int i = 30; i >= w; i--) {
    int j = Get(pre, i);
    if (t[x].son[j])
      x = t[x].son[j];
    else
      return -1;
  }
  return x;
}
long long calc(int pre, int w) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    int newa = a[i] ^ pre, x = go(newa, w);
    if (x == -1) continue;
    ret += t[x].size;
  }
  return ret >> 1;
}
long long Count(int pre, int w) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    int newa = a[i] ^ pre, x = go(newa, w);
    if (x == -1)
      continue;
    else
      for (int j = 0; j <= w; j++)
        ret = (ret + (1LL << j) * ((!Get(a[i], j)) ? t[x].num[j]
                                                   : t[x].size - t[x].num[j])) %
              1000000007;
  }
  return (ret * F) % 1000000007;
}
void solve() {
  int num = 0;
  for (int i = 30; i >= 0; i--) {
    long long newm = calc(num + (1 << i), i);
    if (newm > m)
      num += 1 << i, ans = (int)((ans + (1LL << i) * m) % 1000000007);
    else
      ans = (int)(((long long)ans + Count(num + (1 << i), i)) % 1000000007),
      m -= newm;
  }
  cout << ans << endl;
}
int main() {
  init();
  solve();
  return 0;
}
