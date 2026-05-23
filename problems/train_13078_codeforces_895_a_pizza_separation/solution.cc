#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    long long int n, x, y, i;
    cin >> n;
    int arr[400], brr[400];
    brr[0] = 0;
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      brr[i] = arr[i] + brr[i - 1];
    }
    int ans = brr[n];
    for (i = 1; i <= n; i++) {
      for (x = 1; x <= n; x++) {
        int temp = brr[x] - brr[i - 1];
        ans = min(ans, abs(brr[n] - temp - temp));
      }
    }
    cout << ans << endl;
  }
}
