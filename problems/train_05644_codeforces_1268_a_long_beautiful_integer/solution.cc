#include <bits/stdc++.h>
using namespace std;
long long getpow(long long a, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = ((ans % 1000000007) * (a % 1000000007)) % 1000000007;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
    n /= 2;
  }
  return ans % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, m, t, x, y = 0, f = 0, mn = 10000000009, mx = 0, k, n, z;
  cin >> n >> m;
  string s, s1;
  cin >> s;
  s1 = s;
  for (i = m; i < n; i++) {
    s1[i] = s1[i - m];
  }
  if (s1 < s) {
    for (i = m - 1; i >= 0; i--) {
      s1[i]++;
      if (s1[i] > '9')
        s1[i] = '0';
      else
        break;
    }
    if (s1[0] == '0') s1.insert(s1.begin(), '1');
    for (i = m; i < n; i++) s1[i] = s1[i - m];
  }
  cout << s1.length() << "\n";
  cout << s1;
  return 0;
}
