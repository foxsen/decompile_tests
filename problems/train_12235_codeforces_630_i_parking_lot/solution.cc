#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long temp;
  while (b > 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long fpow(long long b, long long exp, long long mod) {
  if (exp == 0) return 1;
  long long t = fpow(b, exp / 2, mod);
  if (exp & 1) return t * t % mod * b % mod;
  return t * t % mod;
}
long long divmod(long long i, long long j, long long mod) {
  i %= mod, j %= mod;
  return i * fpow(j, mod - 2, mod) % mod;
}
clock_t time_p = clock();
void TimeTaken() {
  time_p = clock() - time_p;
  cerr << "Completion time : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
long long bin_exp(long long a, long long n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 1) {
    return bin_exp(a, n / 2) * bin_exp(a, n / 2) * a;
  } else {
    return bin_exp(a, n / 2) * bin_exp(a, n / 2);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  cout << (n - 3) * 9 * bin_exp((long long)4, n - 3) +
              6 * bin_exp((long long)4, n - 2)
       << "\n";
  return 0;
}
