#include <bits/stdc++.h>
using namespace std;
long long n, a[26], b, ma;
char c;
long long bin(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= a, ans %= 1000000007;
    a *= a, a %= 1000000007;
    n /= 2;
  }
  return ans;
}
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) scanf("\n%c", &c), a[c - 65]++;
  for (long long i = 0; i < 26; i++)
    if (a[i] > ma)
      ma = a[i], b = 1;
    else if (a[i] == ma)
      b++;
  cout << bin(b, n);
}
