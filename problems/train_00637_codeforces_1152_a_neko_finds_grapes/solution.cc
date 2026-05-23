#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, i, j, a, b, o = 0, e = 0, o1 = 0, e1 = 0, c, d;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 1)
      o++;
    else
      e++;
  }
  for (j = 0; j < m; j++) {
    cin >> b;
    if (b % 2 == 1)
      o1++;
    else
      e1++;
  }
  c = min(o, e1);
  d = min(o1, e);
  cout << c + d;
  return 0;
}
