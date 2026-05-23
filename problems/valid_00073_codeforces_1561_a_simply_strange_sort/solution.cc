#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long modx = 998244353;
long double PI = 3.1415926535897;
const long long N = 200010;
unsigned long long pows(unsigned long long x1, long long y1, long long mod) {
  unsigned long long r1 = 1;
  x1 = x1 % mod;
  while (y1 > 0) {
    if (y1 & 1) r1 = (r1 * x1) % mod;
    y1 = y1 >> 1;
    x1 = (x1 * x1) % mod;
  }
  return r1;
}
unsigned long long f[N];
unsigned long long mi(unsigned long long x, long long mod) {
  return pows(x, mod - 2, mod);
}
unsigned long long ncr(unsigned long long x, long long y, long long mod) {
  if (x < y) return 0;
  if (y == 0) return 1;
  long long ans = f[x] * mi(f[y], mod) % mod;
  long long z = (ans * mi(f[x - y], mod) % mod) % mod;
  return z % mod;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
long long ceils(long long x, long long y) { return x / y + ((x % y) != 0); }
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long x, long long y) {
  long long res = 1;
  for (long long i = 0; i < y; i++) {
    res = res * x % MOD;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool COMP(pair<long long, long long> l, pair<long long, long long> r) {
  return l.second < r.second;
}
long long kadanesAlgo(vector<long long> a) {
  long long n = a.size();
  long long currMax = 0;
  long long mx = INT_MIN;
  for (long long i = 0; i < n; i++) {
    currMax += a[i];
    if (currMax <= a[i]) {
      currMax = a[i];
    }
    mx = max(currMax, mx);
  }
  return mx;
}
string ask(long long x, long long y) {
  cout << x + 1 << " " << y + 1;
  string s;
  cin >> s;
  return s;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = x;
  }
  vector<long long> b = a;
  sort((b).begin(), (b).end());
  if (a == b) {
    cout << 0;
    return;
  }
  long long cnt = 0, x = 1;
  while (true) {
    if (a == b) break;
    if (x % 2) {
      for (long long i = 0; i < n - 1; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
        }
      }
    } else {
      for (long long i = 1; i < n - 1; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
        }
      }
    }
    x++;
    cnt++;
  }
  cout << cnt;
}
