#include <bits/stdc++.h>
using namespace std;
const int INF_I = 1e9;
const long long INF_LL = 1e18;
const int MOD = 1000000007;
const double eps = 1e-6;
void solve() {}
long long foo(long long len) { return len * (len + 1) * 0.5; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<long long> p(n + 1);
  p[1] = a[1];
  for (int i = 2; i <= n; i++) p[i] = p[i - 1] + a[i];
  int l = 0, r = 0;
  long long ans = 0;
  set<long long> s = {0};
  for (; l < n; l++) {
    while (r < n && s.find(p[r + 1]) == s.end()) {
      r++;
      s.emplace(p[r]);
    }
    ans += r - l;
    s.erase(p[l]);
  }
  cout << ans << endl;
  return 0;
}
