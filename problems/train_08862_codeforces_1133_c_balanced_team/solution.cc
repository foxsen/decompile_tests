#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long N = 0;
  long long a = 0, b = 0;
  while (a < n) {
    while (b < n && arr[b] - arr[a] <= 5) {
      b++;
    }
    N = max(N, b - a);
    a++;
  }
  cout << N;
  return 0;
}
