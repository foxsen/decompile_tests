#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
const int maxn = 1e2 + 30;
const int maxq = 1e5 + 10;
const int alf = 26;
const long long dlm = 1e9 + 7;
const long long del = 179425601;
const int eps = 1e-7;
string O[] = {"YES", "NO", "Yes", "No"};
int d[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    d[v % k]++;
  }
  int ans = d[0] / 2;
  if (k % 2 == 0) ans += d[k / 2] / 2;
  for (int i = 1; i <= k / 2; i++) {
    if ((k % 2) == 0 && i == (k / 2)) continue;
    int j = k - i;
    ans += min(d[i], d[j]);
  }
  cout << ans * 2;
  return 0;
}
