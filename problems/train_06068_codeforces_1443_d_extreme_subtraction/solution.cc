#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int oo = 1e9 + 7;
const ll mod = 1e9 + 7, maxn = 2e5 + 100, maxm = 1e5 + 100;
const double PI = acos(-1);
string solve() {
  int n, c = 0;
  cin >> n;
  vector<int> mn(n, 0), vs(n);
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
  }
  for (int i = 1; i < n; i++) {
    vs[i] -= c;
    if (vs[i] > vs[i - 1]) c += (vs[i] - vs[i - 1]), vs[i] = vs[i - 1];
    if (vs[i] < 0) return "NO";
  }
  return "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    cout << solve() << endl;
  }
  return 0;
}
