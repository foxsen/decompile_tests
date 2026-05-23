#include <bits/stdc++.h>
using namespace std;
long long int F[1000001], RF[1000001];
long long int delta = 998244353;
long long int POW(long long int a, long long int b) {
  long long int ans = 1;
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    ans = ans * a % delta;
  } else {
    ans = POW(a, b / 2) % delta;
    ans = ans * ans % delta;
    if (b % 2 == 1) ans = ans * a % delta;
  }
  return ans;
}
long long int c(long long int n, long long int r) {
  long long int ans;
  if (n < r) {
    return 0;
  }
  if (r == 0 || n == r) {
    return 1;
  }
  ans = F[n] * RF[r] % delta;
  ans = ans * RF[n - r] % delta;
  return ans;
}
int main() {
  long long int q, ans = 1, t;
  for (int i = 1; i <= 200000; i++) {
    ans = ans * i;
    ans = ans % delta;
    F[i] = ans;
  }
  ans = 1;
  for (int i = 1; i <= 200000; i++) {
    t = POW(i, delta - 2) % delta;
    ans = (ans * t) % delta;
    RF[i] = ans;
  }
  long long int n, k;
  cin >> n >> k;
  long long int h[n + 1];
  q = 0;
  ans = 1;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i < n; i++) {
    if (h[i] != h[i + 1]) q++;
  }
  if (h[n] != h[1]) {
    q++;
  }
  if (k == 1) {
    cout << 0;
    return 0;
  }
  if (q == 1) {
    cout << 0;
    return 0;
  }
  ans = 0;
  long long int pou = POW(k, n) % delta;
  for (int i = 0; i <= q / 2; i++) {
    long long int w = 1;
    w *= POW(k, n - q);
    w %= delta;
    w *= POW(k - 2, q - 2 * i);
    w %= delta;
    w *= c(q, i);
    w %= delta;
    w *= c(q - i, i);
    ans += w;
    ans %= delta;
  }
  pou -= ans;
  pou += delta;
  pou %= delta;
  if (pou % 2 == 0) {
    cout << pou / 2;
    return 0;
  } else {
    cout << (pou + delta) / 2;
    return 0;
  }
}
