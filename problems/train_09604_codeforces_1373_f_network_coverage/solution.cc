#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator*(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator%(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first % x.first, p.second % x.second);
  return np;
}
pair<long long, long long> operator*(const pair<long long, long long> &p,
                                     const pair<int, int> &x) {
  pair<long long, long long> np =
      make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator*(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator+(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first + x.first, p.second + x.second);
  return np;
}
pair<long long, long long> operator-(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first - x.first, p.second - x.second);
  return np;
}
pair<int, int> operator+(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first + x.first, p.second + x.second);
  return np;
}
pair<int, int> operator-(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first - x.first, p.second - x.second);
  return np;
}
vector<int> prime;
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long powerm(long long a, long long k) {
  if (!k) {
    return 1;
  }
  long long b = powerm(a, k / 2);
  b = b * b % 998244353;
  if (k % 2) {
    return a * b % 998244353;
  } else {
    return b;
  }
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long m1 = power(a, b / 2);
  if (b % 2) return m1 * m1 * a;
  return m1 * m1;
}
void PFactor(int x) {
  prime.clear();
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i, prime.push_back(i);
    }
  if (x > 1) prime.push_back(x);
}
bool isprime(long long a) {
  if (a <= 1) return false;
  if (a == 2 || a == 3) return true;
  if (a % 2 == 0 || a % 3 == 0) return false;
  for (long long i = 5; i * i <= a; i = i + 6) {
    if (a % i == 0 || a % (i + 2) == 0) return false;
  }
  return true;
}
const long long N = 2e6 + 20;
vector<long long> g[N];
long long n = 0, m = 0, k = 0;
string str;
long long a[N] = {0};
long long b[N] = {0};
signed main() {
  long long cnt = 0;
  long long T;
  cin >> T;
  while (T--) {
    cnt++;
    cin >> n;
    long long suma = 0, sumb = 0;
    for (long long i = 1; i <= n; i++) scanf("%d", &a[i]), suma += a[i];
    for (long long i = 1; i <= n; i++) scanf("%d", &b[i]), sumb += b[i];
    long long lmax, rmax, sum = 0;
    lmax = rmax = b[n];
    bool flag = (a[1] <= b[n] + b[1]);
    if (suma > sumb) flag = false;
    for (long long i = 2; i <= n; i++)
      if (a[i] > b[i - 1] + b[i]) flag = false;
    long long need = 0, res = sumb, add = 0;
    for (long long i = n; i >= 1; i--) {
      if (b[i] < need) flag = false;
      long long val = b[i] - a[i];
      long long addon = min(res, max(0ll, val - need));
      add += addon;
      res = min(res - addon, b[i] - need - addon);
      need = max(0ll, need - val);
    }
    if (add < need) flag = false;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
