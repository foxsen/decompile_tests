#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, mini = 33;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    mini = min(mini, a[i]);
  }
  cout << 2 + (a[2] ^ mini) << endl;
  return 0;
}
