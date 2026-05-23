#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 10;
const int K = int(2e6) + 10;
const long long MOD = int(1e9) + 7;
const int INF = int(1e9) + 5;
const long long INF64 = 1e18;
map<int, int> mp, ans;
int p[N], q[N];
vector<int> f, s, t;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    q[i] = p[i];
    mp[p[i]]++;
  }
  sort(p + 1, p + 1 + n);
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    if (!mp[p[i]]) continue;
    int x = p[i];
    if (mp[a - x] == 0 && mp[b - x] == 0) {
      ok = false;
    } else if (mp[b - x] == 0) {
      mp[x] = 0;
      mp[a - x] = 0;
      ans[x] = 0;
      ans[a - x] = 0;
    } else if (mp[a - x] == 0) {
      mp[x] = 0;
      mp[b - x] = 0;
      ans[x] = 1;
      ans[b - x] = 1;
    } else {
      int y1 = a - x;
      int y2 = b - x;
      int t1 = a - (b - x);
      int t2 = b - (a - x);
      if (mp[t1] > 0) {
        mp[x] = 0;
        mp[a - x] = 0;
        mp[b - x] = 0;
        mp[t1] = 0;
        ans[x] = ans[a - x] = ans[b - x] = ans[t1] = 0;
      } else if (mp[t2] > 0) {
        mp[x] = 0;
        mp[a - x] = 0;
        mp[b - x] = 0;
        mp[t2] = 0;
        ans[x] = ans[a - x] = ans[b - x] = ans[t2] = 1;
      } else {
        ok = false;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) cout << ans[q[i]] << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
