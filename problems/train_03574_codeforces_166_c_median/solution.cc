#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  int n, x, ans = 0, t;
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  t = n;
  while (arr[(t - 1) / 2] != x) {
    arr[t++] = x;
    sort(arr, arr + t);
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
