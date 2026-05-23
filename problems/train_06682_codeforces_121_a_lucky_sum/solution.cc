#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long int INF = 1e18;
const int N = 100005;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
vector<long long int> V;
void dfs(long long int x) {
  V.push_back(x);
  if (x > inf) return;
  dfs(10 * x + 4);
  dfs(10 * x + 7);
}
long long int Binary_Search(long long int val) {
  long long int lo = 0, hi = V.size() - 1;
  long long int ret = 0;
  while (lo <= hi) {
    long long int mid = (lo + hi) >> 1;
    if (V[mid] >= val) {
      ret = V[mid];
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  dfs(0);
  sort(V.begin(), V.end());
  long long int l, r;
  cin >> l >> r;
  long long int ans = 0;
  while (l <= r) {
    long long int val = Binary_Search(l);
    ans += (min(val, r) - l + 1) * val;
    l = min(val, r) + 1;
  }
  cout << ans << endl;
  return 0;
}
