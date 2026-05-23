#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    long long int ans = 0;
    for (int i = 0; i < n - k; i++) {
      if (i < n - 2 * k)
        ans += ar[i];
      else
        ans += (ar[i] / ar[i + k]);
    }
    cout << ans << endl;
  }
  return 0;
}
