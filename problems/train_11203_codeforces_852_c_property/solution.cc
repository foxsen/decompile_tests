#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 50005;
int b[N], absh[N], ans[N], h[N];
vector<pair<int, int> > vals;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n - 1; i++) vals.push_back({b[i] + b[i + 1], i});
  vals.push_back({b[n - 1] + b[0], n - 1});
  sort(vals.begin(), vals.end());
  int st = 0;
  for (auto u : vals) {
    ans[u.second] = st;
    st++;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
