#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  for (long long int j = 0; j < t; j++) {
    long long int n, max = 0, c = 0;
    cin >> n;
    long long int a[n], b[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    max = a[0];
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      if (a[i] > max) max = a[i];
      long long int d = max - a[i];
      v.push_back(d);
    }
    long long int m = *max_element(v.begin(), v.end());
    while (m > 0) {
      m = m / 2;
      c++;
    }
    cout << c << "\n";
  }
  return 0;
}
