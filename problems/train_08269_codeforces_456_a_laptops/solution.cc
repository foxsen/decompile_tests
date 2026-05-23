#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  int f = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i].second > v[i + 1].second and v[i].first < v[i + 1].first) {
      f = 1;
      break;
    }
  }
  if (f == 1) {
    cout << "Happy Alex" << endl;
  } else {
    cout << "Poor Alex" << endl;
  }
  return 0;
}
