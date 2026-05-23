#include <bits/stdc++.h>
using namespace std;
int ans, a[10];
bool flag = true;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int ad;
    cin >> ad;
    a[ad]++;
  }
  ans += min(a[1], a[2]);
  a[3] += min(a[1], a[2]);
  int ad = min(a[1], a[2]);
  a[1] -= ad;
  a[2] -= ad;
  if (a[1]) {
    ad = (a[1] / 3) * 2;
    ans += ad;
    a[3] += a[1] / 3;
    a[1] %= 3;
    if (a[1] == 1 && a[3])
      ans++;
    else if (a[1] == 1 && a[4] >= 2)
      ans += 2;
    else if (a[1] == 1)
      flag = false;
    if (a[1] == 2 && a[3] >= a[1])
      ans += a[1];
    else if (a[1] == 2 && a[4])
      ans += 2;
    else if (a[1] == 2)
      flag = false;
  } else if (a[2]) {
    ad = a[2] / 3 * 2;
    ans += ad;
    a[2] %= 3;
    a[3] += ad;
    if (a[2] == 2)
      ans += 2;
    else if (a[2] == 1 && a[4])
      ans += 1;
    else if (a[2] == 1 && a[3] >= 2)
      ans += 2;
    else if (a[2])
      flag = false;
  }
  if (flag)
    cout << ans << endl;
  else
    cout << -1;
  return 0;
}
