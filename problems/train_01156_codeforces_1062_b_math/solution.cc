#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int mod = 1e9 + 7;
int dcmp(long double x, long double y) {
  return fabs(x - y) <= 1e-12 ? 0 : x < y ? -1 : 1;
}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n;
map<int, int> mp;
void pf() {
  for (int i = 2; 1ll * i * i <= n; i++) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n > 1) mp[n]++;
}
int main() {
  fast();
  cin >> n;
  pf();
  int cnt = 0, mx = 0;
  int num = 1;
  for (auto e : mp) {
    mx = max(e.second, mx);
    num *= e.first;
  }
  int lo = 0, hi = 30, ans = 1;
  while (lo <= hi) {
    int md = (lo + (hi - lo) / 2);
    if ((1 << md) >= mx) {
      hi = md - 1;
      ans = md;
    } else
      lo = md + 1;
  }
  for (auto e : mp) {
    if (e.second < (1 << ans)) {
      cnt++;
      break;
    }
  }
  cout << num << " ";
  cout << cnt + ans << '\n';
  return 0;
}
