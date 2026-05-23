#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
int n;
int l[MAX];
int r[MAX];
void init() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> l[i];
  for (int i = 0; i < (int)(n); i++) {
    cin >> r[i];
    r[i]++;
  }
}
template <typename T>
T extgcd(T a, T b, T& x, T& y) {
  T d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
template <typename T>
T mod_inv(T a, T m) {
  T x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
long long ans;
long long E[MAX];
void solve() {
  ans = (long long)n;
  for (int i = 0; i < (int)(n - 1); i++) {
    int lm = max(l[i], l[i + 1]);
    int rm = min(r[i], r[i + 1]);
    int dif = max(0, rm - lm);
    long long prod = (((long long)r[i] - l[i]) * (r[i + 1] - l[i + 1])) % MOD;
    E[i] = ((long long)dif * mod_inv(prod, MOD)) % MOD;
    ans = (ans - E[i] + MOD) % MOD;
  }
  ans = (ans * ans) % MOD;
  for (int i = 0; i < (int)(n - 1); i++) {
    ans = (ans + E[i] - (E[i] * E[i]) % MOD + MOD) % MOD;
  }
  for (int i = 1; i <= (int)(n - 2); i++) {
    int lm = max(l[i - 1], max(l[i], l[i + 1]));
    int rm = min(r[i - 1], min(r[i], r[i + 1]));
    int dif = max(0, rm - lm);
    long long prod = (((long long)r[i] - l[i]) * (r[i + 1] - l[i + 1])) % MOD;
    prod = (prod * (r[i - 1] - l[i - 1])) % MOD;
    long long tmp = ((long long)dif * mod_inv(prod, MOD)) % MOD;
    tmp = (tmp - (E[i - 1] * E[i]) % MOD + MOD) % MOD;
    tmp = (2 * tmp) % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
}
void debug() {
  cout << "debug" << endl;
  long long tmp = ((long long)13 * mod_inv((long long)6, MOD));
  cout << (tmp * tmp) % MOD << endl;
}
int main() {
  init();
  solve();
}
