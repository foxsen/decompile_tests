#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    vector<long long> c;
    for (long long i = 0; i < 4; i++) {
      long long k;
      cin >> k;
      long long x[k];
      for (long long j = 0; j < k; j++) cin >> x[j];
      c.push_back(x[k - 1] - x[0]);
    }
    long long ans = max({c[0] * b, c[1] * b, c[2] * a, c[3] * a});
    cout << ans << endl;
  }
}
