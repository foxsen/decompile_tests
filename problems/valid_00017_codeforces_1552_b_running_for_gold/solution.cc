#include <bits/stdc++.h>
using namespace std;
const long long int M = 10000000007;
long long int binarySearch(vector<long long int> arr, long long int l,
                           long long int r, long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int tt, n, i, j, ans, cnt, flag;
  cin >> tt;
  while (tt--) {
    cin >> n;
    vector<vector<long long int> > v(n, (vector<long long int>(5)));
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) {
        cin >> v[i][j];
      }
    }
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    ans = 0;
    for (i = 1; i < n; i++) {
      cnt = 0;
      for (j = 0; j < 5; j++)
        if (v[i][j] < v[ans][j]) cnt++;
      if (cnt >= 3) ans = i;
    }
    flag = 0;
    for (i = 0; i < n; i++) {
      cnt = 0;
      if (i == ans) continue;
      for (j = 0; j < 5; j++)
        if (v[i][j] < v[ans][j]) cnt++;
      if (cnt >= 3) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << ans + 1 << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
