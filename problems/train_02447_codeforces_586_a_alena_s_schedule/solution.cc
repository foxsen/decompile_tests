#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int mark[(10000000 >> 5) + 1];
void sieve() {
  register int i, j, k;
  (mark[1 >> 5] |= 1 << (1 & 31));
  int n = 10000000;
  for (i = 2; i <= n; i++) {
    if (!(mark[i >> 5] >> (i & 31) & 1)) {
      for (k = n / i, j = i * k; k >= i; k--, j -= i)
        (mark[j >> 5] |= 1 << (j & 31));
    }
  }
}
bool is_prime(long long x) {
  if (x == 1) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
long long C(long long n, long long k) {
  if (k == 0) return 1;
  return (n * C(n - 1, k - 1)) / k;
}
long long modular_pow(long long budgetase, long long exponent, int modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * budgetase) % modulus;
    exponent = exponent >> 1;
    budgetase = (budgetase * budgetase) % modulus;
  }
  return result;
}
long long binaryToDec(string number) {
  long long result = 0, pow = 1;
  for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
    result = (result + (number[i] - '0') * pow) % 1000003;
  return result;
}
unsigned long long GCD(unsigned long long a, unsigned long long b) {
  return b == 0 ? a : GCD(b, a % b);
}
int cntMask(int mask) {
  int ret = 0;
  while (mask) {
    if (mask % 2) ret++;
    mask /= 2;
  }
  return ret;
}
int getBit(int mask, int i) { return ((mask >> i) & 1) == 1; }
int setBit(int mask, int i, int value = 1) {
  return (value) ? mask | (1 << i) : (mask & ~(1 << i));
}
unsigned long long mystoi(string s) {
  unsigned long long ans = 0;
  unsigned long long po = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    ans += (s[i] - '0') * po;
    po *= 10;
  }
  return ans;
}
string conv(int i) {
  string t = "";
  while (i) {
    t += '0' + (i % 10);
    i /= 10;
  }
  reverse((t).begin(), (t).end());
  return t;
}
bool hasZero(int i) {
  if (i == 0) return true;
  while (i) {
    if (i % 10 == 0) return true;
    i /= 10;
  }
  return false;
}
int main() {
  int n, a[101];
  cin >> n;
  int idx = -1, f;
  bool flag = true;
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
    if (a[i] == 1) idx = i;
    if (a[i] == 1 && flag) {
      f = i;
      flag = false;
    }
  }
  if (idx == -1)
    cout << 0 << endl;
  else {
    int ans = 0;
    for (int i = f; i <= idx; i++) {
      ans++;
      if (a[i] == 0 && a[i + 1] == 0)
        while (a[i] == 0) i++;
    }
    cout << ans << endl;
  }
  return 0;
}
