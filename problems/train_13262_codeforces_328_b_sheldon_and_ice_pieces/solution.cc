#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  k = n;
  int a[10] = {0};
  int b[10] = {0};
  while (k) {
    a[k % 10]++;
    k = k / 10;
  }
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    b[(s[i] - '0') % 10]++;
  }
  int count, ans = 99999999;
  for (int i = 0; i < 10; ++i) {
    if (a[i] != 0) {
      if (i == 2 || i == 5)
        count = (b[2] + b[5]) / (a[2] + a[5]);
      else if (i == 6 || i == 9)
        count = (b[6] + b[9]) / (a[6] + a[9]);
      else
        count = b[i] / a[i];
      ans = min(ans, count);
    }
  }
  cout << ans << '\n';
  return 0;
}
