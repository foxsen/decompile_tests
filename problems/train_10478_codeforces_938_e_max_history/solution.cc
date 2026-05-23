#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 99;
const long long mod = 1e9 + 7;
long long N, cur, res, arr[MAX], fact[MAX], ifact[MAX];
long long power(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    res %= mod;
    base %= mod;
    exp /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  fact[0] = 1;
  ifact[0] = 1;
  for (long long A = 1; A < MAX; A++) {
    fact[A] = (A * fact[A - 1]) % mod, ifact[A] = power(fact[A], mod - 2);
  }
  cin >> N;
  for (int A = 1; A <= N; A++) cin >> arr[A];
  sort(arr + 1, arr + N + 1);
  for (int A = 1; A <= N; A++) {
    if (arr[A] == arr[N]) break;
    if (A > 1 && arr[A] > arr[A - 1]) cur = A - 1;
    long long tem = ((((fact[cur] * fact[N]) % mod * ifact[cur]) % mod) % mod *
                     power(N - cur, mod - 2)) %
                    mod;
    res = (res + (arr[A] % mod * tem) % mod) % mod;
    if (tem < 0) cout << -1;
  }
  cout << res;
  return 0;
}
