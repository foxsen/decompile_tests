#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long me(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  c_p_c();
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long p1 = 0;
    long long count = 0;
    long long c = 0;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        c++;
      }
    }
    if (c == 0) {
      p1 = s.length();
      if (1) {
        long long y = (p1 - 1) / (k + 1);
        cout << y + 1 << endl;
        continue;
      }
    }
    long long p2 = n - 1;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') {
        p1 = i;
        break;
      }
    }
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        p2 = i;
        break;
      }
    }
    long long temp = p1;
    if (c >= 2) {
      for (long long i = p1 + 1; i <= p2; i++) {
        if (s[i] == '1') {
          long long x = i - temp - 1;
          if (x - k >= 0) {
            x = x - k;
            long long y = x / (k + 1);
            count = count + y;
          }
          temp = i;
        }
      }
    }
    if (1) {
      long long y = p1 / (k + 1);
      count = count + y;
    }
    long long n1 = n - p2 - 1;
    if (1) {
      long long y = n1 / (k + 1);
      count = count + y;
    }
    cout << count << endl;
  }
  return 0;
}
