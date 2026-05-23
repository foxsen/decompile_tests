#include <bits/stdc++.h>
using namespace std;
long long big = pow(10, 13);
int main() {
  long long n;
  cin >> n;
  long long* s = new long long[n];
  long long* c = new long long[n];
  long long* mp = new long long[n];
  for (long long i = 0; i < n; ++i) {
    cin >> s[i];
    mp[i] = big;
  }
  for (long long i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (long long i = 1; i < n; ++i) {
    for (long long t = i - 1; t >= 0; --t) {
      if (s[i] > s[t]) {
        mp[i] = min(mp[i], c[t]);
      }
    }
  }
  long long ans = big;
  long long flag = 0;
  for (long long k = 2; k < n; ++k) {
    for (long long j = k - 1; j >= 0; --j) {
      if (s[k] > s[j] && mp[j] != big) {
        flag = 1;
        ans = min(c[k] + c[j] + mp[j], ans);
      }
    }
  }
  if (flag == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}
