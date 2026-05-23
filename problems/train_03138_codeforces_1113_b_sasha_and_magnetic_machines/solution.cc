#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  long int a[n];
  long int sum = 0;
  for (long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  long int maxres = 0;
  unordered_map<int, int> mp;
  for (long int i = 1; i < n; i++) {
    int f = 2, fs = INT_MAX, minfs = INT_MAX;
    if (mp[a[i]] == 0) {
      while (f * f <= a[i]) {
        if (a[i] % f == 0) {
          int f1 = a[i] / f;
          long a1 = f1 + a[0] * f;
          long b = a[0] * f1 + f;
          fs = min(a1, b);
        }
        minfs = min(minfs, fs);
        f++;
      }
      if (a[i] + a[0] - minfs > 0) {
        maxres = max(maxres, a[i] + a[0] - minfs);
      }
      mp[a[i]] = 1;
    }
  }
  cout << sum - maxres;
  return 0;
}
