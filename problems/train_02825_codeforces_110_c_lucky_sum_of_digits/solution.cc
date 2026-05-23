#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (long long x = 0; x * 4 <= n; ++x) {
    long long r = n - (4 * x);
    if (r % 7 == 0) {
      for (long long i = 1; i <= x; ++i) cout << 4;
      for (long long j = 1; j <= (r / 7); ++j) cout << 7;
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
