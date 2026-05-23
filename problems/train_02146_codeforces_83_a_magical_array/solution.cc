#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long x) {
  if (x == 1) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
bool is_palindrome(string s1) {
  int l = s1.length();
  for (int i = 0; i < l / 2; i++)
    if (s1[i] != s1[l - i - 1]) return false;
  return true;
}
unsigned long long C(long long n, long long k) {
  if (k == 0) return 1;
  return (n * C(n - 1, k - 1)) / k;
}
long long modular_pow(long long base, long long exponent, int modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
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
int main(void) {
  int n;
  int a[100000 + 5];
  cin >> n;
  for (int i = 0; i < int(n); i++) cin >> a[i];
  long long ans = 0;
  long long temp = 0;
  int cur = a[0];
  for (int i = 0; i < int(n); i++) {
    if (a[i] == cur)
      temp++;
    else {
      ans += temp * (temp + 1) / 2;
      temp = 1;
      cur = a[i];
    }
  }
  ans += temp * (temp + 1) / 2;
  cout << ans << endl;
}
