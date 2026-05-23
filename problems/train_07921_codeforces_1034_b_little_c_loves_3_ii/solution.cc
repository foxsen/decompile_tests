#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
int main() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    if (m % 6 <= 3)
      ans = m / 6 * 6;
    else if (m % 6 == 4)
      ans = m / 6 * 6 + 2;
    else if (m % 6 == 5)
      ans = m / 6 * 6 + 4;
  } else if (n == 2) {
    if (m == 7)
      ans = 12;
    else if (m == 1)
      ans = 0;
    else if (m == 2)
      ans = 0;
    else if (m == 3)
      ans = 4;
    else
      ans = m * 2;
  } else {
    ans = n * m;
    if (ans % 2 == 1) --ans;
  }
  cout << ans << endl;
  return 0;
}
