#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = 1;
  long long x = n;
  for (long long i = 2; i * i <= n; i++)
    if (x % i == 0) {
      ans *= (long long)i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) ans *= x;
  cout << ans << endl;
  return 0;
}
