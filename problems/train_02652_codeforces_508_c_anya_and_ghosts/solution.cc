#include <bits/stdc++.h>
using namespace std;
int cnt[1005];
int arr[1005];
int main() {
  int m, t, r, a, ans = 0;
  cin >> m >> t >> r;
  for (int i = 0; i < m; ++i) cin >> arr[i];
  for (int i = 0; i < m; ++i) {
    int k = 0;
    for (int j = arr[i] - 1 + 305; j > arr[i] - t - 1 + 305; --j) {
      if (cnt[j] == 1) k++;
    }
    if (k < r) {
      for (int j = arr[i] - 1 + 305; j > arr[i] - t - 1 + 305; --j) {
        if (cnt[j] == 0) {
          ans++;
          cnt[j] = 1;
          k++;
        }
        if (k == r) break;
      }
      if (k < r) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
