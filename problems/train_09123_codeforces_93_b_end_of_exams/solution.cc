#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, m;
  double x;
  vector<pair<int, int> > a[50];
  int c, k, r, s;
  cin >> n >> w >> m;
  x = (double)(n * w) / m;
  c = 1;
  k = 1;
  r = m;
  for (int i = 0; i < m; ++i) {
    s = 0;
    while (n - s >= r) {
      a[i].push_back(make_pair(c, r));
      s += r;
      ++c;
      k = 1;
      r = m;
    }
    if (s != n) {
      a[i].push_back(make_pair(c, n - s));
      r = m - (n - s);
      ++k;
    }
    if (k > 2) {
      cout << "NO";
      return 0;
    }
  }
  cout.setf(cout.fixed);
  cout.precision(10);
  cout << "YES"
       << "\n";
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < (int)a[i].size(); ++j)
      cout << a[i][j].first << " " << x * a[i][j].second / n << " ";
    cout << "\n";
  }
  return 0;
}
