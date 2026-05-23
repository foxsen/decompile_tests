#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N], b[N];
int main() {
  int n;
  cin >> n;
  a[0] = 0, b[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] == b[i - 1])
      ans += min(a[i], b[i]) - a[i - 1];
    else if (a[i - 1] < b[i - 1])
      ans += min(b[i] - b[i - 1] + 1, max(a[i] - b[i - 1] + 1, 0));
    else if (a[i - 1] > b[i - 1])
      ans += min(a[i] - a[i - 1] + 1, max(b[i] - a[i - 1] + 1, 0));
  }
  cout << ans << endl;
  return 0;
}
