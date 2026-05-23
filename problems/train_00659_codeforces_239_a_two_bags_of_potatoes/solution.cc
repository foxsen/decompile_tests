#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}
int main() {
  int y, k, n;
  cin >> y >> k >> n;
  int f = 0;
  int d = y / k;
  int e = n / k;
  for (int i = d + 1; i <= e; i++) {
    cout << k * i - y << " ";
    f = 1;
  }
  if (f == 0) cout << -1 << endl;
  return 0;
}
