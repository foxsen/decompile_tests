#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << '\n';
  ;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &x) {
  cin >> x;
}
template <typename T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a).size(); i++) re(a[i]);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <typename T>
void pr(T x) {
  cout << x << '\n';
  ;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << '\n';
  ;
}
void ps() {
  cout << '\n';
  ;
}
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
const long long MOD = 1000000007;
long double PI = 4 * atan(1);
long double eps = 1e-12;
long long calcpow(long long b, long long p) {
  long long pw = b;
  long long res = 1;
  long long initp = p;
  while (p > 0) {
    if (p % 2 == 0) {
      p /= 2;
    } else {
      res *= pw;
      res %= MOD;
      p -= 1;
      p /= 2;
    }
    pw *= pw;
    pw %= MOD;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long cnt[200001] = {};
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  long long prod = 1;
  bool no_odd = true;
  for (int i = 0; i < 200001; i++) {
    if (cnt[i] > 0 && (cnt[i] % 2 == 1) && no_odd) {
      no_odd = false;
      prod *= (cnt[i] + 1) / 2;
    } else {
      prod *= cnt[i] + 1;
    }
    prod %= (MOD - 1);
  }
  long long ans = 1;
  for (int i = 0; i < 200001; i++) {
    if (cnt[i] > 0) {
      long long pw = prod * cnt[i];
      if (no_odd) pw /= 2;
      pw %= (MOD - 1);
      ans *= calcpow((long long)i, pw);
      ans %= MOD;
    }
  }
  cout << ans << '\n';
  ;
}
