#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long m = -1, index = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] - (i + 1) > m) {
        m = a[i] - i - 1;
      }
    }
    if (m > 0)
      cout << m << endl;
    else
      cout << 0 << endl;
  }
}
