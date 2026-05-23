#include <bits/stdc++.h>
using namespace std;
int a[100010];
vector<int> f[100010];
long long mypow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res *= x;
      res %= 1000000007;
    }
    x *= x;
    x %= 1000000007;
    y >>= 1;
  }
  return res;
}
int main() {
  int i, j, k, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= 100000; i++) {
    for (j = i; j <= 100000; j += i) {
      f[j].push_back(i);
    }
  }
  sort(a + 1, a + 1 + n);
  int now = 1;
  long long an = 1;
  for (i = 2; i <= a[n]; i++) {
    while (now <= n && i > a[now]) now++;
    long long res = mypow((int)f[i].size(), n - now + 1) -
                    mypow((int)f[i].size() - 1, n - now + 1);
    while (res < 0) res += 1000000007;
    int ll = 1;
    for (j = 1; j < f[i].size(); j++) {
      int rr = lower_bound(a + ll, a + n + 1, f[i][j]) - a;
      res = res * mypow(j, rr - ll) % 1000000007;
      ll = rr;
    }
    an += res;
  }
  an %= 1000000007;
  if (an < 0) an += 1000000007;
  cout << an << endl;
  return 0;
}
