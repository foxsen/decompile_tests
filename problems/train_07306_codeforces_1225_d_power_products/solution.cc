#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, k, a[N], p[N], tot;
long long ans;
map<int, int> M, st[N];
map<int, int>::iterator it, itt;
bool np[N];
void getp() {
  for (int i = 2; i <= 100000; i++) {
    if (!np[i]) p[tot++] = i;
    for (int j = 0; j < tot; j++) {
      if (i * p[j] > 100000) break;
      np[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
int pow(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = ret * x;
    x = x * x, n >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  getp();
  for (int x, y, i = 1; i <= n; i++) {
    scanf("%d", &x);
    M.clear();
    for (int j = 0; j < tot; j++) {
      while (x % p[j] == 0) M[p[j]]++, x /= p[j];
      if (x == 1 || !np[x]) break;
    }
    if (x ^ 1) M[x]++;
    for (it = M.begin(); it != M.end(); it++) it->second %= k;
    x = 1, y = 1;
    for (it = M.begin(); it != M.end(); it++) {
      if (it->second) x *= it->first;
      y *= pow(it->first, it->second);
    }
    st[x][y]++;
  }
  for (int i = 1; i <= 100000; i++) {
    if (st[i].size() == 0) continue;
    long long x = 1ll;
    for (int j = 1; j <= k; j++, x *= i)
      if (x * i >= 1e10) goto end;
    for (it = st[i].begin(); it != st[i].end(); it++) {
      if (it->first > x / it->first) break;
      itt = st[i].find(x / it->first);
      if (itt == st[i].end()) continue;
      if (it->first == itt->first)
        ans += 1ll * it->second * (it->second - 1) / 2;
      else
        ans += 1ll * it->second * itt->second;
    }
  end:;
  }
  printf("%I64d\n", ans);
}
