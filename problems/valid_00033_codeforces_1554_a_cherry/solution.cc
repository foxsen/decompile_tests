#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tcase;
  cin >> tcase;
  while (tcase--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long ans = 1;
    if (n == 2)
      ans = arr[0] * arr[1];
    else {
      for (int i = 1; i < n; i++) {
        ans = max(ans, arr[i] * arr[i - 1]);
      }
    }
    cout << ans << "\n";
  }
}
