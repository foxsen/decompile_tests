#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, x;
  long long int k, res, temp, sum;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    res = 1000000000000000000;
    sum = 0;
    int a[n];
    long long int b[n];
    for (i = 0; i < n; i++) {
      cin >> x;
      sum += x;
      a[i] = x;
    }
    b[0] = sum;
    sort(a, a + n);
    for (i = n - 1; i > 0; i--) {
      sum = sum - a[i] + a[0];
      b[n - i] = sum;
    }
    for (i = 0; i < n; i++) {
      if (b[i] <= k)
        temp = i;
      else {
        if ((b[i] - k) % (i + 1) == 0)
          temp = i + (b[i] - k) / (i + 1);
        else
          temp = i + 1 + (b[i] - k) / (i + 1);
      }
      if (temp < res) res = temp;
    }
    cout << res << endl;
  }
  return 0;
}
