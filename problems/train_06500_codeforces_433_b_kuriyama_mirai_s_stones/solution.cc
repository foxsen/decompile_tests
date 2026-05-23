#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n];
  long long sum[n + 1];
  long long sorted_sum[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum[i + 1] = sum[i] + arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    sorted_sum[i + 1] = sorted_sum[i] + arr[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1)
      cout << sum[r] - sum[l - 1] << endl;
    else
      cout << sorted_sum[r] - sorted_sum[l - 1] << endl;
  }
  return 0;
}
