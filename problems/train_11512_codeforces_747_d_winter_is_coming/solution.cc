#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 10;
const int N = 200010;
const int MOD = 1e9 + 7;
int n, k;
int a[N];
vector<pair<int, int>> vec;
int sign(int x) { return x < 0 ? -1 : 1; }
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] < 0) cnt++;
  if (cnt > k) {
    cout << -1;
    return 0;
  }
  int l = 1;
  while (l <= n) {
    int r = l;
    while (r <= n && sign(a[l]) == sign(a[r])) r++;
    r--;
    vec.push_back(make_pair(sign(a[l]), r - l + 1));
    l = r + 1;
  }
  if (vec.size() == 1) {
    if (sign(a[1]) == 1)
      cout << 0;
    else
      cout << 1;
    return 0;
  }
  int delta = k - cnt;
  int ans = 1;
  int add = 0;
  vector<int> tot;
  for (int i = 0; i < (int)vec.size() - 1; i++)
    if (vec[i].first == -1) {
      if (i + 1 != vec.size() - 1)
        tot.push_back(vec[i + 1].second);
      else
        add = vec[i + 1].second;
    }
  sort(tot.begin(), tot.end());
  for (int i = 0; i < (int)tot.size(); i++) {
    if (delta >= tot[i])
      delta -= tot[i];
    else
      ans += 2;
  }
  cout << ans + (delta < add);
  return 0;
}
