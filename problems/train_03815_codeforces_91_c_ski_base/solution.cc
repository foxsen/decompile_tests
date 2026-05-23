#include <bits/stdc++.h>
int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}
double nextDouble() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long nextLong() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
char nextChar() {
  char x;
  scanf("%c", &x);
  return x;
}
void newLine() { printf("\n"); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long powM(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
long long ModExp(long long n, long long k, long long MOD) {
  long long ans = 1;
  while (k > 0) {
    if (k & 1) ans = (ans * n) % MOD;
    n = (n * n) % MOD;
    k /= 2;
  }
  return ans;
}
long long Exp(long long n, long long k) {
  long long ans = 1;
  while (k > 0) {
    if (k & 1) ans = (ans * n);
    n = (n * n);
    k /= 2;
  }
  return ans;
}
int countSetBits(long long n) {
  int ans = 0;
  while (n != 0) {
    n -= (n & -n);
    ++ans;
  }
  return ans;
}
const int N = 100100;
const int M = 12;
const int INF = 1e6;
const double EPS = 1e-6;
const long double PI = 2 * acos(0);
using namespace std;
const int LOG = 18;
long long mod = 1000000009;
int par[N];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); };
bool same(int x, int y) { return getPar(x) == getPar(y); }
void merge(int x, int y) {
  int xx = getPar(x);
  int yy = getPar(y);
  if (xx != yy) par[xx] = yy;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) par[i] = i;
  long long ans = 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (same(x, y)) {
      ans = (ans * 2ll) % mod;
    } else {
      merge(x, y);
    }
    cout << (ans + mod - 1) % mod << endl;
  }
  return 0;
}
