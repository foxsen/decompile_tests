#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nextPrime(long long N) {
  if (N <= 1) return 2;
  long long prime = N;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
long long fact(long long n) {
  if (n == 1) return 1;
  return n * fact(n - 1);
}
long long cl(long long n, long long d) { return (n + d - 1) / d; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
long long Pow(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * x);
    x = (x * x);
    n >>= 1;
  }
  return ans;
}
void solve() {
  long long k, i;
  cin >> k;
  if (!k) {
    cout << 'a';
    return;
  }
  vector<long long> v;
  for (i = 2000; i >= 2; i--) {
    while (k - (i * (i - 1)) / 2 >= 0) {
      v.push_back(i);
      k = k - (i * (i - 1)) / 2;
    }
  }
  char c = 'a';
  for (long long x : v) {
    for (i = 0; i < x; i++) {
      cout << c;
    }
    c++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
