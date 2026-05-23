#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l, r, n, x, k, p, i, q, m;
  cin >> n >> x >> k;
  long long int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long int cnt = 0, ind1, ind2;
  for (i = 0; i < n; i++) {
    l = (ceil((double)arr[i] / x) + (k - 1)) * x;
    r = l + (x - 1);
    if (k == 0) {
      l = arr[i];
      r = ceil((double)arr[i] / x) * x - 1;
    }
    ind1 = lower_bound(arr, arr + n, l) - arr;
    ind2 = upper_bound(arr, arr + n, r) - arr;
    cnt += (ind2 - ind1);
  }
  cout << cnt << endl;
  return 0;
}
