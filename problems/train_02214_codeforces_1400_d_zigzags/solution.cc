#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[n];
    vector<vector<int>> v(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      v[arr[i]].push_back(i);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int y = (upper_bound(v[arr[j]].begin(), v[arr[j]].end(), i) -
                 v[arr[j]].begin());
        if (arr[i] == arr[j]) y--;
        int x = (upper_bound(v[arr[i]].begin(), v[arr[i]].end(), j) -
                 v[arr[i]].begin());
        x = v[arr[i]].size() - x;
        ans += (long long)((long long)x * (long long)y);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
