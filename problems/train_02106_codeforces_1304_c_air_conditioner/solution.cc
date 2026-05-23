#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int flag = 1;
    long long mx, mi;
    long long m, t, time;
    cin >> m >> t;
    mx = mi = t;
    time = 0;
    while (m--) {
      long long a, b, c;
      cin >> a >> b >> c;
      mx = mx + (a - time);
      mi = mi - (a - time);
      time = a;
      if (mx < b || mi > c) {
        flag = 0;
      } else {
        mx = min(mx, c);
        mi = max(mi, b);
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
