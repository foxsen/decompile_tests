#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  vector<pair<int, int> > vp(n);
  int ans = min(2, n);
  int count = 1;
  int l = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i] > v[i - 1])
      ++count;
    else {
      int temp = count;
      for (int j = l; j < i; ++j) vp[j].first = temp--;
      ans = max(ans, count + 1);
      count = 1;
      l = i;
    }
  }
  ans = max(ans, count + 1);
  for (int j = l; j < n; ++j) vp[j].first = count--;
  count = 1;
  l = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    if (v[i] < v[i + 1])
      ++count;
    else {
      int temp = count;
      for (int j = l; j > i; --j) vp[j].second = temp--;
      count = 1;
      l = i;
    }
  }
  for (int j = l; j >= 0; --j) vp[j].second = count--;
  for (int i = 1; i < n - 1; ++i)
    if (v[i - 1] + 1 < v[i + 1])
      ans = max(ans, vp[i - 1].second + vp[i + 1].first + 1);
  ans = min(ans, n);
  cout << ans;
}
