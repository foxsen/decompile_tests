#include <bits/stdc++.h>
using namespace std;
long long i, j, k;
long long first[300005], l[300005], ans[300005], arr[300005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (i = 1; i < n + 1; i++) {
      cin >> arr[i];
      first[i] = l[i] = 0;
      ans[i] = -1;
    }
    for (i = 1; i < n + 1; i++) {
      first[arr[i]] = max(first[arr[i]], i - l[arr[i]]);
      l[arr[i]] = i;
    }
    for (i = 1; i < n + 1; i++) {
      first[i] = max(first[i], n + 1 - l[i]);
      for (int x = first[i]; x <= n && ans[x] == -1; x++) {
        ans[x] = i;
      }
    }
    for (i = 1; i < n + 1; i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
