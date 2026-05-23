#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k <= n) {
    cout << ((k - 1) / 2) << endl;
  } else if (k <= 2 * n - 1) {
    cout << (2 * n - k + 1) / 2 << endl;
  } else {
    cout << 0 << endl;
  }
}
