#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main() {
  long long n, s;
  cin >> n >> s;
  for (long long i = 0; i < n; i++) {
    long long k, m;
    cin >> k >> m;
    a[k] = max(a[k], m);
  }
  long long ans = 0, last = s;
  for (long long i = s; i > 0; i--) {
    if (a[i]) {
      ans = max(ans + last - i, a[i]);
      last = i;
    }
  }
  cout << ans + last;
  return 0;
}
