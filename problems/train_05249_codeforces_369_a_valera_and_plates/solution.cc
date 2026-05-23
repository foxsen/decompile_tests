#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, i;
int main() {
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a == 1)
      m--;
    else if (a == 2 && k > 0)
      k--;
    else
      m--;
  }
  if (m >= 0)
    cout << 0;
  else
    cout << -m;
}
