#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
pair<int, int> arr[200010];
int ans[200010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i].first, arr[i].second = i;
  for (int i = 1; i <= k; i++) {
    cin >> a >> b;
    if (arr[a].first == arr[b].first) continue;
    if (arr[a].first > arr[b].first)
      ans[a]--;
    else
      ans[b]--;
  }
  sort(arr + 1, arr + n + 1);
  a = 1;
  ans[arr[a].second] = 0;
  for (int i = 2; i <= n; i++) {
    if (arr[i].first == arr[a].first) {
      ans[arr[i].second] += (a - 1);
    } else {
      a = i;
      ans[arr[i].second] += (a - 1);
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
