#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long x = 3;
  cin >> n;
  while (1) {
    if (n % x != 0) break;
    x *= 3;
  }
  long long ans = n / x;
  cout << ans + 1 << endl;
  return 0;
}
