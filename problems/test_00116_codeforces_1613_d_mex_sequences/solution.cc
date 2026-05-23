#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
long long fpow(long long n, long long k, long long m = 998244353) {
  if (k == 1) return n % m;
  if (k == 0) return 1 % m;
  long long t = fpow(n % m, k / 2, m);
  return (k % 2 == 0) ? ((t * t) % m) : (((t * t % m) * (n % m)) % m);
}
int q;
long long n, a[500005], cnt1[500005], cnt2[500005], c1;
void exeCute() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(cnt1, 0, sizeof(long long) * (n + 2));
  memset(cnt2, 0, sizeof(long long) * (n + 2));
  c1 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0)
      cnt1[a[i]] = (cnt1[a[i]] * 2 + 1) % 998244353;
    else {
      cnt1[a[i]] = (cnt1[a[i]] * 2 + cnt1[a[i] - 1]) % 998244353;
    }
    cnt2[a[i]] = (cnt2[a[i]] * 2) % 998244353;
    if (a[i] >= 2) cnt2[a[i]] = (cnt2[a[i]] + cnt1[a[i] - 2]) % 998244353;
    if (cnt2[a[i] + 2] > 0) cnt2[a[i] + 2] = (cnt2[a[i] + 2] * 2) % 998244353;
    c1 += (a[i] == 1);
  }
  long long ans = (fpow(2, c1) - 1 + 998244353) % 998244353;
  for (int i = 0; i <= n; i++) ans = (ans + cnt1[i] + cnt2[i]) % 998244353;
  cout << ans << endl;
}
void init() {
  cin >> q;
  for (int i = 0; i < q; i++) exeCute();
}
int main(int argc, char* argv[]) {
  init();
  return 0;
}
