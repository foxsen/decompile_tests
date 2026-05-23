#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n, u;
  cin >> n >> u;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  double maxi = -1;
  for (int x = 0; x < (int)v.size() - 2; x++) {
    double i = v[x], j = v[x + 1], k = 0;
    vector<int>::iterator it = lower_bound(v.begin() + x + 2, v.end(), i + u);
    if (v[x + 2] > i + u) {
      continue;
    } else if (v[n - 1] <= i + u) {
      k = v[n - 1];
    } else {
      if (*it > i + u) it--;
      k = *it;
    }
    double res = (k - j) / (k - i);
    maxi = max(maxi, res);
  }
  cout << fixed << setprecision(12) << maxi;
  return 0;
}
