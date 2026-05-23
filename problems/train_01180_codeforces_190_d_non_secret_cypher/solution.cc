#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
const int N = 4e5 + 5;
int n, k, a[N];
map<int, int> M;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int L = 1, R = 0;
  bool ok = false;
  long long ans = 0;
  while (R <= n) {
    if (ok) {
      ans += n - R + 1;
      if (--M[a[L++]] == k - 1) ok = false;
    } else {
      if (++M[a[++R]] == k) ok = true;
    }
  }
  cout << ans << '\n';
  return 0;
}
