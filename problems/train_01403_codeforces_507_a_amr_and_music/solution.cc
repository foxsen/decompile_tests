#include <bits/stdc++.h>
using namespace std;
int a[100], b[100];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) b[i] = i + 1;
  vector<pair<int, int>> vect;
  for (int i = 0; i < n; ++i) {
    vect.push_back(make_pair(a[i], b[i]));
  }
  sort(vect.begin(), vect.end());
  for (int i = 0; i < n; ++i) {
    a[i] = vect[i].first;
    b[i] = vect[i].second;
  }
  int count = 0, S = 0;
  for (int i = 0; i < n; ++i) {
    S += a[i];
    if (S > k)
      break;
    else
      ++count;
  }
  if (a[0] > k)
    cout << "0" << endl;
  else {
    cout << count << endl;
    for (int i = 0; i < count; ++i) {
      cout << b[i] << " ";
    }
  }
  return 0;
}
