#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[100]{};
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      ans = min(ans, arr[i]);
    }
    int cnt = 0;
    bool flag = false;
    while (cnt != 2) {
      flag = false;
      for (int i = 0; i < n; ++i) {
        arr[i] = arr[i] & ans;
      }
      for (int i = 0; i < n; ++i) {
        if (arr[i] < ans) {
          ans = arr[i];
          flag = true;
        }
      }
      if (flag) {
        cnt = 0;
      } else {
        ++cnt;
      }
    }
    cout << ans << endl;
  }
}
