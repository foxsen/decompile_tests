#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long m, t, n, ar[maxn], br[maxn];
char s[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  long long ans = 1;
  if (n > m) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      ans = ans * (ar[i] - ar[j]) % m;
      if (ans == 0) break;
    }
  cout << abs(ans) << '\n';
  return 0;
}
