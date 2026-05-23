#include <bits/stdc++.h>
const int inf = 1 << 30;
const long long INF = 1ll << 61;
using namespace std;
int t;
int n;
bool isprime[100000 + 5];
int prime[100000 + 5];
int k;
void make_prime() {
  memset(isprime, false, sizeof(isprime));
  for (int i = 2; i < 100005; i++)
    if (!isprime[i])
      for (int j = i * 2; j < 100005; j += i) isprime[j] = true;
  for (int i = 2; i < 100005; i++)
    if (!isprime[i]) prime[k++] = i;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool isok(int x) {
  if (x < 100000) return !isprime[x];
  for (int i = 0; i < k && prime[i] <= x; i++)
    if (x % prime[i] == 0) return false;
  return true;
}
long long upfind(int x) {
  for (int i = n + 1;; i++)
    if (isok(i)) return i;
  return 0;
}
long long underfind(int x) {
  for (int i = n; i >= 2; i--)
    if (isok(i)) return i;
  return 0;
}
void init() {}
bool input() {
  while (cin >> n) {
    return false;
  }
  return true;
}
void cal() {
  long long u = upfind(n);
  long long v = underfind(n);
  long long p = u * v + 2 * (n - u - v + 1);
  long long q = 2 * u * v;
  long long d = gcd(p, q);
  cout << p / d << "/" << q / d << endl;
}
void output() {}
int main() {
  make_prime();
  cin >> t;
  while (t--) {
    init();
    if (input()) return 0;
    cal();
    output();
  }
  return 0;
}
