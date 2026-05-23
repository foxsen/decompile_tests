#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  while (testcases--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    long long freq[102] = {0};
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      freq[arr[i]]++;
    }
    long long m = 0;
    long long count = 0;
    bool check = false;
    for (long long i = 0; i < 102; i++) {
      if (freq[i] > k) {
        long long x = freq[i] / k;
        if (x > m) {
          m = x;
          if (freq[i] % k == 0)
            check = true;
          else
            check = false;
        }
      }
      if (freq[i] != 0) {
        count++;
      }
    }
    if (check)
      m = m;
    else
      m = m + 1;
    long long c = (m)*k * count;
    cout << c - n << endl;
  }
}
