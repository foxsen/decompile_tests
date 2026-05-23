#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    long long m = 1;
    for (int i = 0; i < k - 1; i++) {
      n -= m;
      m += 2;
      if (n < 0) break;
    }
    if (n >= m && n % 2 == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
