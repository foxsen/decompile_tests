#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
const int maxn = 101010;
const long long inf = 2020202020202020202LL;
int n, a[maxn];
long long pow2[maxn], ans = 1, fact[maxn], revfact[maxn], lol = 1;
void upd_ans(long long t) { ans = (ans * t) % md; }
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return (binpow(a, n - 1) * a) % md;
  else {
    long long b = binpow(a, n / 2);
    return (b * b) % md;
  }
}
void do_fact() {
  fact[0] = 1;
  revfact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = (i * fact[i - 1]) % md;
    revfact[i] = binpow(fact[i], md - 2);
  }
}
long long do_c(long long k, long long n) {
  if (k < 0) return 0;
  if (k > n) return 0;
  long long r = 1;
  r = r * fact[n];
  r = (r * revfact[k]) % md;
  r = (r * revfact[n - k]) % md;
  return r;
}
long long doit(int l, int r, int it1, int it2, int low) {
  if (l > r) return 1;
  if (it1 > it2) return pow2[r - l];
  if (it1 <= it2) {
    long long s1 = 0, s2 = 0;
    if (a[it1] >= a[it2]) {
      if (a[it1] > low)
        lol = 0;
      else {
        low = a[it1];
        s1 = (do_c(it1 - l, r - l - a[it1] + 1));
        int l0 = it1 + 1;
        int r0 = it1 + a[it1] - 1;
        int it10 = it1 + 1;
        while ((!a[it10]) && (it10 < n)) it10++;
        s1 = (s1 * doit(l0, r0, it10, it2, low)) % md;
      }
    }
    if (a[it1] <= a[it2]) {
      if (a[it2] > low)
        lol = 0;
      else {
        low = a[it2];
        s2 = do_c(r - it2, r - l - a[it2] + 1);
        int r0 = it2 - 1;
        int l0 = it2 - a[it2] + 1;
        int it20 = it2 - 1;
        while ((!a[it20]) && (it20 >= 0)) it20--;
        s2 = (s2 * doit(l0, r0, it1, it20, low)) % md;
      }
    }
    if ((a[it1] != 1) || (a[it2] != 1)) s1 = (s1 + s2) % md;
    return s1;
  }
}
int main() {
  cin >> n;
  do_fact();
  int it1 = md, it2 = 0;
  pow2[0] = 1;
  for (int i = 0; i < n; i++) pow2[i + 1] = (pow2[i] << 1) % md;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]) it2 = i;
    if (a[i] && (it1 == md)) it1 = i;
  }
  ans = doit(0, n - 1, it1, it2, md);
  ans = ans * lol;
  cout << ans;
  cin >> n;
  return 0;
}
