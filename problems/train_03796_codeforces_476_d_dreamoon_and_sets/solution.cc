#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  long long ans = k * (6 * n - 1);
  cout << ans << endl;
  long long tmp = 0;
  for (int i = 0; i < n; i++) {
    cout << k * (tmp + 1) << " " << k * (tmp + 2) << " " << k * (tmp + 3) << " "
         << k * (tmp + 5) << endl;
    tmp += 6;
  }
  return 0;
}
