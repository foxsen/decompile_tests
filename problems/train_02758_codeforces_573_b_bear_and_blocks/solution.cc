#include <bits/stdc++.h>
using namespace std;
int n, h[100005], ans[100005], res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int i = 1; i <= n; i++) {
    ans[i] = min(1 + ans[i - 1], h[i]);
  }
  for (int i = n; i > 0; i--) {
    ans[i] = min(1 + ans[i + 1], ans[i]);
    res = max(res, ans[i]);
  }
  cout << res << endl;
  return 0;
}
