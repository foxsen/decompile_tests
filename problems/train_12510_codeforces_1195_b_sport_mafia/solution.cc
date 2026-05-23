#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    if ((i * (i + 1)) / 2 >= k && i + (i * (i + 1)) / 2 - k == n) {
      cout << (i * (i + 1)) / 2 - k << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
