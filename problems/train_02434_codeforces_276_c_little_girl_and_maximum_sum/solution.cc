#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const int NINF = INT_MIN;
int n, q, l, r, curr;
vector<int> vec, tv, Count;
void Solve() {
  cin >> n >> q;
  vec = tv = vector<int>(n, 0);
  for (int i = 0; i <= n - 1; i++) cin >> vec[i];
  for (int i = 0; i <= q - 1; i++) {
    cin >> l >> r;
    l--;
    r;
    tv[l]++;
    if (r < n) tv[r]--;
  }
  curr = 0;
  for (int i = 0; i <= n - 1; i++) {
    curr += tv[i];
    if (curr > 0) Count.push_back(curr);
  }
  sort(Count.rbegin(), Count.rend());
  sort(vec.rbegin(), vec.rend());
  long long int ans = 0ll;
  int i = 0;
  for (auto v : Count) {
    ans += ((v * 1ll) * (vec[i] * 1ll));
    i++;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
