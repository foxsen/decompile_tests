#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long s1 = a + b;
    long long s2 = c + d;
    if (s1 > s2)
      cout << s1 << endl;
    else
      cout << s2 << endl;
  }
}
