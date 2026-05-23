#include <bits/stdc++.h>
using namespace std;
int main() {
  long int x, y, z;
  cin >> x >> y >> z;
  long int x1, y1, z1;
  cin >> x1 >> y1 >> z1;
  long int a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  long int ans = 0;
  if (y < 0) ans += a1;
  if (y > y1) ans += a2;
  if (z < 0) ans += a3;
  if (z > z1) ans += a4;
  if (x < 0) ans += a5;
  if (x > x1) ans += a6;
  cout << ans;
}
