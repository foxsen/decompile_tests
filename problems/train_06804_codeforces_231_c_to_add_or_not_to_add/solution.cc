#include <bits/stdc++.h>
using namespace std;
long long a[200000];
int n, i, ans, j, x;
long long sum, k, num;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    a[i] = x;
  }
  sort(a, a + n);
  sum = 0;
  ans = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    if (i > 0) sum = sum + (a[i] - a[i - 1]) * (i - j);
    while (sum > k) {
      sum -= (a[i] - a[j]);
      j++;
    }
    if ((i - j + 1) > ans) {
      ans = (i - j + 1);
      num = a[i];
    }
  }
  cout << ans << " " << num << endl;
  return 0;
}
