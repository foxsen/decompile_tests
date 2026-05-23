#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  map<int, int> mp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
    if (mp[x] > ans) ans = mp[x];
  }
  cout << n - ans;
  return 0;
}
