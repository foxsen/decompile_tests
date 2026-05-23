#include <bits/stdc++.h>
using namespace std;
const int base = 100003;
const long long MM = 1ll * 1000000007 * 1000000007;
int n, p[1000005];
void Solve() {
  cin >> n;
  int l = 2e9;
  int r = -1;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    p[x] = i;
  }
  for (int i = 1; i <= n; ++i) {
    r = max(r, p[i]);
    l = min(l, p[i]);
    if (r - l + 1 == i)
      cout << 1;
    else
      cout << 0;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) Solve();
}
