#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
long long Q;
bool is_prime(long long x) {
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool is_prime2(long long x) {
  auto it = lower_bound((primes).begin(), (primes).end(), x);
  if (it != primes.end() && *it == x) return true;
  for (long long p : primes) {
    if (x % p == 0) return false;
    if (p > x) break;
  }
  return true;
}
long long v(long long x) {
  while (true) {
    if (is_prime2(x)) return x;
    x--;
  }
}
long long u(long long x) {
  while (true) {
    x++;
    if (is_prime2(x)) return x;
  }
}
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
pair<long long, long long> f(long long x) {
  long long l = v(x), r = u(x);
  long long a = (l * r) - 2LL * l - 2LL * r + 2LL * x + 2LL;
  long long b = 2LL * l * r;
  long long g = gcd(a, b);
  return pair<long long, long long>(a / g, b / g);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (long long i = 2; i <= 31622; i++) {
    if (is_prime(i)) primes.push_back(i);
  }
  cin >> Q;
  for (long long i = 0; i < (Q); i++) {
    long long x;
    cin >> x;
    pair<long long, long long> p = f(x);
    cout << p.first << "/" << p.second << "\n";
  }
  return 0;
}
