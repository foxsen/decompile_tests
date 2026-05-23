#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  int t = 1;
  while (a || b) {
    int x = a % 3;
    int y = b % 3;
    int z = (y - x + 3) % 3;
    ans += z * t;
    t *= 3;
    a /= 3, b /= 3;
  }
  cout << ans << endl;
}
