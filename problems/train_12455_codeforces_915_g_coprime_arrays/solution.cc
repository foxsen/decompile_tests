#include <bits/stdc++.h>
using namespace std;
const long long mxDv = 7;
const long long mskDv = 1 << mxDv;
long long fpow(long long &a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * fpow(a, b ^ 1)) % 1000000007l;
  long long d = fpow(a, b >> 1);
  return (d * d) % 1000000007l;
}
void Solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> primes(k + 1), pos(k + 1), pw(k + 1), df(mskDv), sgn(mskDv);
  for (long long i = 1; i < mskDv; ++i) sgn[i] = sgn[i & (i - 1)] ^ 1;
  primes[1] = 1;
  for (long long i = 2; i <= k; ++i) {
    if (primes[i] == 0) {
      primes[i] = i;
      for (long long j = i * i; j < primes.size(); j += i)
        if (!primes[j]) primes[j] = i;
    }
  }
  for (long long i = 1; i <= k; ++i) {
    if (i == primes[i])
      pw[i] = fpow(i, n);
    else
      pw[i] = (pw[primes[i]] * pw[i / primes[i]]) % 1000000007l;
  }
  long long ans = 0, cnt_diff = 0;
  for (long long i = 1; i <= k; ++i) {
    long long q = i;
    long long sz = 0;
    while (q != 1) {
      long long d = primes[q];
      df[1 << sz++] = d;
      while (primes[q] == d) q /= d;
    }
    sz = 1 << sz;
    for (long long j = 1, r = 0; j < sz; r = j & (j + 1), ++j) {
      if (r) df[j] = df[r] * df[j ^ r];
      cnt_diff += ((sgn[j] << 1) - 1) * (pw[pos[df[j]] + 1] - pw[pos[df[j]]]);
      pos[df[j]]++;
      if (cnt_diff < 0) cnt_diff += 1000000007l;
      if (cnt_diff >= 1000000007l) cnt_diff -= 1000000007l;
    }
    long long sm = pw[i] - cnt_diff;
    if (sm < 0) sm += 1000000007l;
    ans += sm ^ i;
  }
  cout << ans % 1000000007l;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
