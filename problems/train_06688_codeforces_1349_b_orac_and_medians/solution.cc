#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
long long fac[1], inv[1];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long cmb(long long r, long long c) {
  return fac[r] * inv[c] % MOD * inv[r - c] % MOD;
}
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[200001];
int vec[100000];
int k;
int go(int l, int r) {
  if (l >= r) return 0;
  int mid = (l + r) / 2;
  if (go(l, mid) || go(mid + 1, r)) return 1;
  int x = 0, s = 0, lm = -1e8, rm = -1e8;
  for (int i = mid; i >= l; i--) {
    if (k == vec[i])
      s++;
    else if (k > vec[i])
      x--;
    else
      x++;
    if (x + s >= 1 && mid - i + 1 >= 2) return 1;
    lm = max(lm, x + s);
  }
  x = s = 0;
  for (int i = mid + 1; i <= r; i++) {
    if (k == vec[i])
      s++;
    else if (k > vec[i])
      x--;
    else
      x++;
    if (x + s >= 1 && i - mid >= 2) return 1;
    if (lm + x + s >= 1) return 1;
    rm = max(rm, x + s);
  }
  x = s = 0;
  for (int i = mid; i >= l; i--) {
    if (k == vec[i])
      s++;
    else if (k > vec[i])
      x--;
    else
      x++;
    if (rm + x + s >= 1) return 1;
  }
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %d", &n, &k);
    int x = 0, s = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &vec[i]);
      if (k == vec[i]) flag = 1;
    }
    if (!flag)
      printf("no\n");
    else {
      if (n == 1)
        printf("yes\n");
      else
        printf("%s", go(0, n - 1) ? "yes\n" : "no\n");
    }
  }
}
