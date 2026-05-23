#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  vector<int> house, shop;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'H')
      house.push_back(i);
    else if (s[i] == 'S')
      shop.push_back(i);
  }
  if (house.back() >= t) {
    cout << -1 << endl;
    return 0;
  }
  int left = max(0, (int)(house.size() - shop.size()));
  int right = house.size();
  while (left < right) {
    int mid = (left + right) / 2;
    int ret = INT_MAX;
    int edge = max(house.back(), shop[house.size() - mid - 1]);
    int pos = -1;
    int step = edge + 1;
    for (unsigned i = mid; i < house.size(); ++i) {
      ret = min(ret, step + edge - house[i]);
      if (house[i] < shop[i - mid]) {
        step += (shop[i - mid] - max(house[i], pos)) * 2;
        pos = shop[i - mid];
      }
    }
    if (ret <= t)
      right = mid;
    else
      left = mid + 1;
  }
  cout << left << endl;
  return 0;
}
