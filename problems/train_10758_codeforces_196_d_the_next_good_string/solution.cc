#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int exp(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = 1LL * ret * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ret;
}
int inv(int x) { return exp(x, mod - 2); }
int po[400010], invp[400010];
int N, D;
string S, T;
int sum1[400010], sum2[400010], offset;
int calc1(int l, int r) {
  return (sum1[r] + mod -
          1LL * (l == 0 ? 0 : sum1[l - 1]) * po[r - l + 1] % mod) %
         mod;
}
int calc2(int l, int r) {
  return (1LL * (sum2[l] + offset) * invp[l] % mod + mod -
          (1LL * (sum2[r + 1] + offset) * invp[r + 1] % mod) * po[r - l + 1] %
              mod) %
         mod;
}
bool chk(int x) {
  if (x + 1 >= D && calc1(x - D + 1, x) == calc2(x - D + 1, x)) return true;
  if (x + 1 >= D + 1 && calc1(x - D, x) == calc2(x - D, x)) return true;
  return false;
}
bool f(int x) {
  int t = 1;
  for (int i = x; i < N; i++) {
    bool ok = false;
    for (int j = t ? S[i] - 'a' + 1 : 0; j < 26; j++) {
      T.push_back('a' + j);
      sum1[i] = 1LL * (i == 0 ? 0 : sum1[i - 1]) * 27 % mod + T[i] - 'a' + 1;
      sum1[i] %= mod;
      offset += 1LL * po[i] * (T[i] - 'a' + 1) % mod;
      offset %= mod;
      sum2[i + 1] = mod - offset;
      sum2[i + 1] %= mod;
      if (chk(i)) {
        offset += mod - 1LL * po[i] * (T[i] - 'a' + 1) % mod;
        offset %= mod;
        T.pop_back();
        continue;
      } else {
        ok = true;
        t = 0;
        break;
      }
    }
    if (!ok) return false;
    if (i == N - 1 && !t) return true;
  }
  return false;
}
int main() {
  po[0] = 1;
  for (int i = 1; i < 400010; i++) {
    po[i] = 1LL * po[i - 1] * 27 % mod;
  }
  for (int i = 0; i < 400010; i++) {
    invp[i] = inv(po[i]);
  }
  cin >> D >> S;
  N = S.size();
  T.clear();
  int p = N;
  for (int i = 0; i < N; i++) {
    T.push_back(S[i]);
    sum1[i] = 1LL * (i == 0 ? 0 : sum1[i - 1]) * 27 % mod + T[i] - 'a' + 1;
    sum1[i] %= mod;
    offset += 1LL * po[i] * (T[i] - 'a' + 1) % mod;
    offset %= mod;
    sum2[i + 1] = mod - offset;
    sum2[i + 1] %= mod;
    if (chk(i)) {
      p = i;
      offset += mod - 1LL * po[i] * (T[i] - 'a' + 1) % mod;
      offset %= mod;
      T.pop_back();
      break;
    }
  }
  for (int i = p; i >= 0; i--) {
    if (f(i)) {
      cout << T;
      return 0;
    }
    if (i == 0) {
      printf("Impossible");
      return 0;
    }
    offset += mod - 1LL * po[i - 1] * (T[i - 1] - 'a' + 1) % mod;
    offset %= mod;
    T.pop_back();
  }
}
