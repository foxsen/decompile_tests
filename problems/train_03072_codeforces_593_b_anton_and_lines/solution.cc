#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, k, b, n, x1, x2, prev1, prev2;
  cin >> n;
  cin >> x1 >> x2;
  vector<pair<long long, long long> > y(n);
  for (i = 0; i < n; i++) {
    cin >> k >> b;
    y[i] = make_pair(k * x1 + b, k * x2 + b);
  }
  sort(y.begin(), y.end());
  prev1 = y[0].first;
  prev2 = y[0].second;
  for (i = 1; i < n; i++) {
    if (y[i].second < prev2) {
      cout << "YES";
      return 0;
    }
    prev2 = max(prev2, y[i].second);
  }
  cout << "NO";
  return 0;
}
