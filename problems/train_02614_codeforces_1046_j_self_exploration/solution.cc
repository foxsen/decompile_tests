#include <bits/stdc++.h>
using namespace std;
const int maxn = int(2e5) + 100;
const int mod = int(1e9) + 7;
struct binary {
  int n;
  int a[maxn];
  void read() {
    char ch;
    while ((ch = getchar()) != '0' && ch != '1')
      ;
    a[n = 1] = ch - '0';
    while ((ch = getchar()) == '0' || ch == '1') a[++n] = ch - '0';
    for (int i = 1; i <= n / 2; ++i) swap(a[i], a[n - i + 1]);
  }
  void dec() {
    --a[1];
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= 0)
        break;
      else {
        a[i] += 2;
        --a[i + 1];
      }
    }
    while (n > 0 && a[n] == 0) --n;
  }
};
binary A, B;
long long fact[maxn], nfact[maxn];
int origin[maxn], cnt[maxn];
long long getC(int n, int m) {
  if (n == -1) return (m == 0);
  return fact[n] * nfact[m] % mod * nfact[n - m] % mod;
}
int calc(bool flag) {
  if (flag) {
    if (cnt[2] - cnt[1] != 0 && cnt[2] - cnt[1] != 1) return 0;
    return getC(cnt[2] - 1 + cnt[0], cnt[0]) *
           getC(cnt[1] + 1 - 1 + cnt[3], cnt[3]) % mod;
  } else {
    if (cnt[2] - cnt[1] != 0 && cnt[1] - cnt[2] != 1) return 0;
    return getC(cnt[2] + 1 - 1 + cnt[0], cnt[0]) *
           getC(cnt[1] - 1 + cnt[3], cnt[3]) % mod;
  }
}
int work(binary num) {
  for (int i = 0; i < 4; ++i) cnt[i] = origin[i];
  long long ans = 0;
  int i;
  for (i = num.n - 1; i > 0; --i) {
    if (num.a[i] == 1) {
      if (cnt[num.a[i + 1] * 2] > 0) {
        --cnt[num.a[i + 1] * 2];
        ans = (ans + calc(0)) % mod;
        ++cnt[num.a[i + 1] * 2];
      }
    }
    if ((--cnt[num.a[i + 1] * 2 + num.a[i]]) < 0) break;
  }
  if (i == 0) ans = (ans + 1) % mod;
  return ans;
}
int POW(long long num, long long times) {
  long long ans = 1;
  while (times) {
    if (times & 1LL) ans = ans * num % mod;
    num = num * num % mod;
    times >>= 1;
  }
  return ans;
}
void solve() {
  int n = 1;
  for (int i = 0; i < 4; ++i) n += origin[i];
  if (n > B.n || A.n > n) {
    puts("0");
    return;
  }
  fact[0] = nfact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    nfact[i] = POW(fact[i], mod - 2);
  }
  for (int i = 0; i < 4; ++i) cnt[i] = origin[i];
  int sA = 0, sB = calc(1);
  if (A.n == n) sA = work(A);
  if (B.n == n) sB = work(B);
  printf("%d\n", (sB - sA + mod) % mod);
}
int main() {
  A.read();
  A.dec();
  B.read();
  for (int i = 0; i < 4; ++i) scanf("%d", &origin[i]);
  solve();
  return 0;
}
