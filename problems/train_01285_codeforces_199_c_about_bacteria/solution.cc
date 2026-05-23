#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  long long int k, b, n, t;
  while (cin >> k >> b >> n >> t) {
    long long int s = 1;
    long long int cas = 0;
    while (s <= t && cas < n) {
      s = s * k + b;
      cas++;
    }
    if (cas == n && s <= t)
      cout << 0 << endl;
    else
      cout << n - cas + 1 << endl;
  }
  return 0;
}
