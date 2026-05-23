#include <bits/stdc++.h>
using namespace std;
bool valid(long long x, long long y, long long z) { return x + y > z; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << 1 << " " << n - 1 << "\n";
  }
}
