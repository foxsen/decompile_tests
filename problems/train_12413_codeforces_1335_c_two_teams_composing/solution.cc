#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
bool f(int mid) {
  if (mp.size() < mid) return false;
  int a = 0, b = 0;
  bool fl = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second > mid) {
      a = mid;
      if (fl == 0) {
        b++;
      } else {
        b += 2;
        fl = 0;
      }
    } else if (it->second == mid) {
      if (a == 0) {
        a = mid;
        fl = 1;
      } else
        b++;
    } else if (it->second < mid)
      b++;
  }
  return a >= mid && b >= mid;
}
int main() {
  int test;
  cin >> test;
  for (int t = 1; t <= test; t++) {
    int n, ans = 0, imax = 0;
    cin >> n;
    mp.clear();
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      mp[temp]++;
      imax = max(imax, mp[temp]);
    }
    int low = 1, high = imax;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (f(mid)) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    cout << ans << endl;
  }
}
