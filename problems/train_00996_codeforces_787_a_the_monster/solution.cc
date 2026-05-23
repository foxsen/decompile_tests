#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = 0; i <= 1e6; i++) {
    long long x = (i * c) + d - b;
    if (x < 0) continue;
    if (x % a == 0) {
      cout << x + b;
      return 0;
    }
  }
  cout << "-1";
}
