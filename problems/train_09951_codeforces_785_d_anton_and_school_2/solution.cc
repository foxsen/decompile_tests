#include <bits/stdc++.h>
using namespace std;
template <typename T>
T expo(T base, T e, T mod) {
  T res = 1;
  while (e > 0) {
    if (e & 1) res = res * base % mod;
    base = base * base % mod;
    e >>= 1;
  }
  return res;
}
template <typename T, typename S>
T expo(T b, S e) {
  if (e <= 1) return e == 0 ? 1 : b;
  return (e & 1) == 0 ? expo((b * b), e >> 1) : (b * expo((b * b), e >> 1));
}
template <typename T, typename S>
T modinv(T a, S mod) {
  return expo(a, mod - 2, mod);
}
long long fact[200001];
inline void init() {
  fact[0] = 1;
  for (__typeof(200000) i = 1; i <= 200000; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007ll;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  init();
  long long n = (int)(s).size();
  long long x[n], y[n];
  x[0] = y[n - 1] = 0;
  if (s[0] == '(') x[0]++;
  if (s[n - 1] == ')') y[n - 1]++;
  for (__typeof(n - 1) i = 1; i <= n - 1; i++) x[i] = x[i - 1] + (s[i] == '(');
  for (long i = n - 2; i >= 0; i--) y[i] = y[i + 1] + (s[i] == ')');
  long long ans = 0;
  for (__typeof(n) i = 0; i < n; i++) {
    long long aux = fact[x[i] + y[i] - 1];
    long long div1 = (fact[x[i]] * fact[y[i] - 1]) % 1000000007ll;
    div1 = expo(div1, 1000000007ll - 2, 1000000007ll);
    aux = (aux * div1) % 1000000007ll;
    if (s[i] == '(' && y[i]) ans = (ans + aux) % 1000000007ll;
  }
  cout << ans;
  return 0;
}
