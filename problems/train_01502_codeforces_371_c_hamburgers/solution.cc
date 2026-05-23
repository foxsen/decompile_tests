#include <bits/stdc++.h>
using namespace std;
int const MOD = (int)1e9 + 7;
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
inline long long mod(long long a, long long m) {
  if (a < 0)
    return m - (abs(a) % m);
  else if (a < m)
    return a;
  else
    return (a % m);
}
const int N = 300007;
const int MAX = 1000000;
const int INF = 1e9;
string str;
long long b, s, c, br, sr, cr;
long long push_back, ps, pc, r;
bool chk(long long x) {
  long long t1 = 0, t2 = 0, t3 = 0;
  if (br) t1 = ((x * br) - b) * push_back;
  if (sr) t2 = ((x * sr) - s) * ps;
  if (cr) t3 = ((x * cr) - c) * pc;
  long long cost = max(0LL, t1) + max(0LL, t2) + max(0LL, t3);
  if (cost > r)
    return false;
  else
    return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  cin >> b >> s >> c >> push_back >> ps >> pc;
  cin >> r;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'B') br++;
    if (str[i] == 'S') sr++;
    if (str[i] == 'C') cr++;
  }
  long long l = 0, r = 2e12;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (chk(mid) == true) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << endl;
}
