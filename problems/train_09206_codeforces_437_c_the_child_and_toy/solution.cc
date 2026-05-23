#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1e5 + 7;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, x, y;
  cin >> n >> m;
  long long ans = 0;
  vector<int> vi(n + 1);
  for (int i = 1; i <= n; i++) cin >> vi[i];
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    ans += (min(vi[x], vi[y]));
  }
  std::cout << ans << '\n';
  return 0;
}
