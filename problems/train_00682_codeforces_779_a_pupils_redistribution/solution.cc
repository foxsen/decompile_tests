#include <bits/stdc++.h>
using namespace std;
int n, a[200], b[200], t, ans;
map<int, int> mp;
map<int, int> c;
map<int, int> d;
set<int> s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    c[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[b[i]]++;
    d[b[i]]++;
  }
  for (int i = 0; i < mp.size(); i++) {
    if (mp[i] % 2 == 1) {
      cout << -1;
      t++;
      break;
    }
  }
  if (t == 0) {
    for (int i = 0; i < mp.size(); i++) {
      ans += abs(c[i] - d[i]);
    }
    cout << ans / 4;
  }
}
