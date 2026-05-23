#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5, MOD = 1000000007;
int n, a[111], c, c1;
vector<int> ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0; i < n; ++i) {
    c1++;
    if (a[i] < 0) c++;
    if (c == 3) {
      ans.push_back(c1 - 1);
      c = 0;
      c1 = 0;
      i--;
    }
    if (i == n - 1) ans.push_back(c1);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  return 0;
}
