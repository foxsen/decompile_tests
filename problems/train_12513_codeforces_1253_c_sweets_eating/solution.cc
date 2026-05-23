#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i < m) {
      ans += arr[i];
      cout << ans << " ";
      arr[i] = ans;
    } else {
      ans += arr[i] + arr[i - m];
      cout << ans << " ";
      arr[i] = ans;
      ans = ans - arr[i - m];
    }
  }
}
