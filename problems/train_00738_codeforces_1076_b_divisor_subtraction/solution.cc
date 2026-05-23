#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  if (n % 2 == 0) {
    cout << n / 2 << endl;
    return 0;
  }
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      cout << (n - i) / 2 + 1 << endl;
      return 0;
    }
  cout << 1 << endl;
}
