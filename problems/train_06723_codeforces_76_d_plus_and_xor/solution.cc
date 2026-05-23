#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, b;
  cin >> a >> b;
  if (a < b || a % 2 != b % 2) {
    cout << "-1\n";
    return 0;
  }
  unsigned long long x = (a - b) / 2;
  unsigned long long y = x + b;
  if ((x & (a - x)) != x) {
    cout << "-1\n";
    return 0;
  }
  cout << x << " " << y << "\n";
  return 0;
}
