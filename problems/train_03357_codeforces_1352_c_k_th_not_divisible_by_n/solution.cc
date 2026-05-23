#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long d = (k / (n - 1)), r = (k % (n - 1));
    if (r != 0) {
      cout << (d * n) + r << endl;
    } else {
      cout << (d * n) - 1 << endl;
    }
  }
  return 0;
}
