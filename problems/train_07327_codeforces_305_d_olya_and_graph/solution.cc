#include <bits/stdc++.h>
using namespace std;
int B[1000006 + 1] = {}, n, m, k, a, b, l = 0, r;
bool af = 0;
long long pow(int e) {
  if (e == 0) return 1;
  long long s = pow(e / 2);
  s = (s * s) % 1000000007;
  if (e % 2 == 0)
    return s;
  else
    return (s * 2) % 1000000007;
}
int g(int a, int b) { return B[b] - B[a - 1]; }
long long solve() {
  for (int i = n - k; i <= n; i++) B[i] = 1;
  for (int i = 1; i <= n; i++) B[i] += B[i - 1];
  if (l == 0) {
    if (n > 2 * k) return ((n - 2 * k) * pow(k)) % 1000000007;
    return pow(n - k - 1);
  }
  long long ans = 0;
  for (int i = max(1, r - k); i < l; i++) {
    ans += pow(k - g(i + 1, i + k)), ans %= 1000000007;
  }
  return (ans + pow(k - g(l + 1, l + k))) % 1000000007;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  while (m--) {
    scanf("%d %d", &a, &b);
    if (a == b - 1) continue;
    if (b != a + k + 1) {
      af = 1;
      continue;
    }
    if (l and l + k + 1 <= a) {
      af = 1;
      continue;
    }
    B[a] = 1;
    if (!l) l = a;
    r = a;
  }
  if (af)
    cout << 0 << endl;
  else if (k >= n - 1)
    cout << 1 << endl;
  else
    cout << solve() % 1000000007 << endl;
}
