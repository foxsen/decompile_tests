#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    long long int a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;
    a -= b;
    long long int e = c - d;
    if (a <= 0)
      cout << b << "\n";
    else if (d >= c)
      cout << -1 << "\n";
    else {
      if (a % e == 0)
        ans = a / e;
      else
        ans = a / e + 1;
      cout << ans * c + b << "\n";
    }
  }
}
