#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long double PI = 3.141592653589793;
int main() {
  ios_base::sync_with_stdio(false);
  long long int t;
  cin >> t;
  long long int l = 0, r = 0;
  set<long long int> le, ri;
  vector<long long int> v(2e5 + 10);
  while (t--) {
    char a;
    long long int b;
    cin >> a >> b;
    if (l == 0 && r == 0) {
      v[b] = 1;
      l++;
      r++;
      continue;
    }
    if (a == 'L') {
      l++;
      le.insert(b);
      v[b] = l;
    } else if (a == 'R') {
      r++;
      ri.insert(b);
      v[b] = r;
    } else {
      auto k = le.find(b);
      if (k != le.end())
        cout << min(l - (v[b] - 1), r + (v[b] - 1)) - 1;
      else
        cout << min(r - (v[b] - 1), l + (v[b] - 1)) - 1;
      cout << '\n';
    }
  }
  cerr << "Time Lapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}
