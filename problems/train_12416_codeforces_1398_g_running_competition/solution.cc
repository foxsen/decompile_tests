#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ans;
}
long long find(long long i, long long a[]) {
  if (a[i] == i) return i;
  return a[i] = find(a[i], a);
}
void uni(long long i, long long j, long long a[], long long sz[]) {
  long long x = find(i, a);
  long long y = find(j, a);
  if (sz[x] > sz[y])
    a[y] = x;
  else
    a[x] = y;
  sz[x] += sz[y];
  sz[y] = sz[x];
}
long long ans[1000006];
bitset<200005> b1, b2;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, x, y;
  cin >> n >> x >> y;
  n = n + 1;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  b1.reset();
  b2.reset();
  for (long long i = 1; i < n; i++) {
    b2.set(0, 1);
    b2 <<= (a[i] - a[i - 1]);
    b1 |= b2;
  }
  memset(ans, -1, sizeof(ans));
  for (long long i = 1; i <= x; i++) {
    if (b1[i]) {
      for (long long j = (2 * i + 2 * y); j <= 1000000; j += 2 * i + 2 * y) {
        ans[j] = 2 * i + 2 * y;
      }
    }
  }
  long long q;
  cin >> q;
  while (q--) {
    long long x1;
    cin >> x1;
    cout << ans[x1] << " ";
  }
  return 0;
}
