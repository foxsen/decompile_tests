#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  int start = 1;
  int i = 0;
  int T = 0;
  while (true) {
    if (start + t <= a[i].first) {
      start += t;
    } else {
      T += a[i].second - start + 1;
      start = a[i].second + 1;
      i++;
    }
    if (i == n) break;
  }
  cout << T << endl;
  return 0;
}
