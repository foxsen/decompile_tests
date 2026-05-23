#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long t1, t2;
  long long r = 0;
  cin >> n;
  long long ai;
  for (long long i = 0; i < n; i++) {
    cin >> ai;
    r += ai;
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> t1 >> t2;
    if (r >= t1 && r <= t2) {
      cout << r;
      return 0;
    } else {
      if (r < t1) {
        cout << t1;
        return 0;
      }
    }
  }
  cout << -1;
}
