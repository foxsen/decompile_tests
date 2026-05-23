#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long n, m;
  while (cin >> n >> m) {
    set<long long> s;
    bool ok = true;
    for (int i = 1; i <= m && ok; i++) {
      int mod = n % i;
      if (s.count(mod)) {
        ok = false;
      }
      s.insert(mod);
    }
    if (ok)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
