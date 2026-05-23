#include <bits/stdc++.h>
using namespace std;
int64_t fast(int64_t x, int64_t y, int64_t p) {
  x %= p;
  int64_t res = 1;
  while (y) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y >>= 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  int64_t n = s.length();
  int64_t a, b;
  cin >> a >> b;
  int64_t pre[n];
  for (int64_t i = 0; i < n; i++) {
    pre[i] = 0;
  }
  pre[0] = (int64_t(s[0] - '0')) % a;
  for (int64_t i = 1; i < n; i++) {
    pre[i] = (pre[i - 1] * 10 + int64_t(s[i] - '0')) % a;
  }
  int64_t suf[n];
  for (int64_t i = 0; i < n; i++) {
    suf[i] = 0;
  }
  suf[n - 1] = (int64_t(s[n - 1] - '0')) % b;
  for (int64_t i = n - 2; i >= 0; i--) {
    suf[i] = (suf[i + 1] + int64_t(s[i] - '0') * fast(10, n - i - 1, b)) % b;
  }
  for (int64_t i = 0; i < n - 1; i++) {
    if (pre[i] == suf[i + 1] && pre[i] == 0 && s[i + 1] != '0') {
      cout << "YES"
           << "\n";
      cout << s.substr(0, i + 1) << "\n";
      cout << s.substr(i + 1) << "\n";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
