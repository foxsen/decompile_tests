#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, x, countt = 0;
  cin >> n;
  double d = 0, k = 0;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
    d += x;
  }
  k = d;
  d = d / (n * 1.0);
  if (d > 4.50)
    cout << 0;
  else {
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it < v.end(); it++) {
      if (*it > 4) break;
      if (*it < 5 && d < 4.5) {
        countt++;
        k += (5 - (*it));
        d = (k / (n * 1.0));
        if (d >= 4.5) {
          break;
        }
      }
    }
    cout << countt;
  }
  return 0;
}
