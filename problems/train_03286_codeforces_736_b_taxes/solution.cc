#include <bits/stdc++.h>
using namespace std;
long long prime(long long n) {
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  if (prime(n))
    cout << 1;
  else if (n % 2 == 0)
    cout << 2;
  else if (prime(n - 2))
    cout << 2;
  else
    cout << 3;
  return 0;
}
