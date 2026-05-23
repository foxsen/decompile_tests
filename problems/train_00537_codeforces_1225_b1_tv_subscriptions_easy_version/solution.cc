#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9 + 5;
const double PI = acos(-1);
const int X[] = {1, -1, 0, 0};
const int Y[] = {0, 0, 1, -1};
const int mod = 1e9 + 7;
int t, n, k, d;
map<int, int> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k >> d;
    int a[n + 5];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= d; i++) {
      if (!mp[a[i]]) {
        ++cnt;
      }
      mp[a[i]]++;
    }
    int l = 1, ans = cnt;
    for (int i = d + 1; i <= n; i++) {
      mp[a[l]]--;
      if (mp[a[l]] == 0) {
        --cnt;
      }
      ++l;
      if (!mp[a[i]]) {
        ++cnt;
      }
      mp[a[i]]++;
      ans = min(ans, cnt);
    }
    cout << ans << "\n";
    mp.clear();
  }
  return 0;
}
