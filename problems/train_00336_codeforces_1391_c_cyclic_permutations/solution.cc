#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
long long binpow(long long, long long);
long long mult(long long, long long);
long long add(long long, long long);
long long division(long long, long long);
long long nCr(long long, long long);
long long inv(long long);
void calc();
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
  }
  return os;
}
const int N = 1000005;
long long fact[N];
void solve() {
  long long n;
  cin >> n;
  cout << (fact[n] - binpow(2, n - 1) + 1000000007) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  calc();
  for (long long i = 0; i < t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
long long add(long long a, long long b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
  while (a < 0) a += 1000000007;
  return a;
}
long long mult(long long a, long long b) { return (a * 1ll * b) % 1000000007; }
long long binpow(long long a, long long b) {
  long long c = 1;
  while (b > 0) {
    if (b % 2 == 1) c = mult(c, a);
    a = mult(a, a);
    b /= 2;
  }
  return c;
}
long long inv(long long a) { return binpow(a, 1000000007 - 2); }
long long division(long long a, long long b) { return mult(a, inv(b)); }
void calc() {
  fact[0] = 1;
  for (long long i = 1; i <= N - 1; i++)
    fact[i] = (i * 1ll * fact[i - 1]) % 1000000007;
}
