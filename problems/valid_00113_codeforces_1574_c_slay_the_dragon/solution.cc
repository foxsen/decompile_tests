#include <bits/stdc++.h>
using namespace std;
void fileio() {}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n, 0);
  set<long long int> s;
  long long int tot = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
    tot += arr[i];
  }
  long long int m;
  cin >> m;
  for (long long int yy = 0; yy <= m - 1; yy++) {
    long long int x, y;
    cin >> x >> y;
    auto it = s.lower_bound(x);
    long long int ans = -1;
    if (it != s.end()) {
      long long int a = (*it);
      long long int castleprotector = tot - a;
      if (castleprotector < y) {
        ans = y - castleprotector;
      } else {
        ans = 0;
      }
    }
    if (it != s.begin()) {
      it--;
      long long int a = (*it);
      long long int castleprotector = tot - a;
      long long int req = (x - a);
      if (castleprotector < y) {
        req += (y - castleprotector);
      }
      if (ans == -1) {
        ans = req;
      } else {
        ans = min(ans, req);
      }
    }
    if (ans == -1) {
      ans = 0;
    }
    cout << ans << "\n";
  }
}
int32_t main() {
  fileio();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  for (long long int yy = 1; yy <= t; yy++) {
    solve();
  }
  return 0;
}
