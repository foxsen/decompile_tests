#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 11;
long long num[28];
long long num2[28];
char s[N], lm[N];
long long len;
long long fac[N];
long long inv[N];
long long finv[N];
long long powmod(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
void initt() {
  fac[0] = inv[0] = finv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  for (int i = 1; i < N; i++) {
    finv[i] = powmod(fac[i], mod - 2, mod);
  }
}
long long solve(long long *num, char *s) {
  long long ans = 0, tt = 1;
  for (int i = 0; i < len; i++) {
    long long t = 0;
    for (int j = 0; j < s[i]; j++) {
      t += num[j];
    }
    ans = (ans + tt * t % mod * fac[len - i - 1] % mod) % mod;
    if (num[s[i]] == 0) break;
    tt = tt * num[s[i]] % mod;
    if (num[s[i]] > 0) num[s[i]]--;
  }
  return ans;
}
int main() {
  initt();
  scanf("%s", s);
  scanf("%s", lm);
  len = strlen(s);
  for (int i = 0; i < len; i++) {
    s[i] -= 'a';
    num[s[i]]++;
  }
  for (int i = 0; i < len; i++) {
    lm[i] -= 'a';
  }
  if (strcmp(s, lm) == 0) {
    puts("0");
    return 0;
  }
  long long tt = 1;
  for (int i = 0; i < 26; i++) {
    tt = tt * finv[num[i]] % mod;
  }
  for (int i = 0; i < 26; i++) num2[i] = num[i];
  long long ans = solve(num, lm) - solve(num2, s);
  printf("%lld\n", (ans % mod * tt % mod + mod - 1) % mod);
}
