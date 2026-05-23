#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const long long inf = 1e18 + 7;
const int mod = 1e9 + 7;
int q;
long long k, a[10], b[50], c[10], ci[10];
long long wer(long long nub, long long k) {
  int ct = 0;
  while (ci[ct] < k) ct++;
  k = k - ci[ct - 1];
  long long ki = (k - 1) / ct + c[ct] / 9;
  long long cnt = ct - (k - 1) % ct;
  while (--cnt) {
    ki = ki / 10;
  }
  return ki % 10;
}
int main() {
  long long h = 9;
  ci[0] = 0;
  c[0] = 0;
  for (int i = 1; i <= 9; i++) {
    c[i] = h;
    ci[i] = ci[i - 1] + i * c[i];
    h *= 10;
  }
  a[0] = 0;
  for (int i = 1; i <= 9; i++) {
    a[i] = a[i - 1] + (2 * ci[i - 1] + i * c[i] + i) * c[i] / 2;
  }
  int th = 1;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= i; j++) {
      b[th++] = j;
    }
  }
  cin >> q;
  while (q--) {
    cin >> k;
    int ct = 0;
    while (a[ct] < k) ct++;
    if (ct == 1) {
      cout << b[k] << endl;
      continue;
    }
    k = k - a[ct - 1];
    long long l = 1, r = c[ct], mid, kh;
    while (l <= r) {
      mid = (l + r) / 2;
      if ((2 * ci[ct - 1] + ct * mid + ct) * mid / 2 >= k) {
        r = mid - 1;
        kh = mid;
      } else
        l = mid + 1;
    }
    long long ans = c[ct] / 9 - 1 + kh;
    k = k - ((2 * ci[ct - 1] + ct * kh) * (kh - 1) / 2);
    cout << wer(ans, k) << endl;
  }
  return 0;
}
