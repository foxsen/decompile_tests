#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  cout << max(0LL, n - m * 2) << " ";
  for (long long i = 0; i <= n; i++) {
    if (i * (i - 1) / 2 >= m) {
      cout << n - i;
      return 0;
    }
  }
  cout << 0;
}
