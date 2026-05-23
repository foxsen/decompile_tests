#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9;
int mo = 998244353;
int a[N], ex[N] = {0};
int mod(int x, int p) { return (x % p + p) % p; }
int main() {
  int n, p;
  cin >> n >> p;
  vector<int> Ans;
  for (auto i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (auto i = (a[n] - n + 1); i <= (a[n]); ++i) {
    ex[mod(i - (upper_bound(a + 1, a + n + 1, i) - (a + 1)), p)]++;
  }
  for (auto x = (max(0, a[n] - n + 1)); x <= (a[n]); ++x) {
    if (!ex[x % p]) Ans.push_back(x);
    ex[mod(x - (upper_bound(a + 1, a + n + 1, x) - (a + 1)), p)]--;
    ex[mod(x + n - (upper_bound(a + 1, a + n + 1, x + n) - (a + 1)), p)]++;
  }
  cout << Ans.size() << endl;
  for (auto i = (1); i <= (Ans.size()); ++i) cout << Ans[i - 1] << " ";
  cout << endl;
  return 0;
}
