#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long MOD = 998244353;
int n, k;
int a[maxn], s[maxn];
vector<int> vt;
long long ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ans = 0;
  for (int i = 0; i < k; i++) ans += n - i;
  cout << ans << ' ';
  for (int i = 1; i <= n; i++)
    if (a[i] <= n - k)
      s[i] = s[i - 1] + 1;
    else {
      s[i] = 0;
      vt.push_back(i);
    }
  ans = 1;
  for (int i = 1; i < vt.size(); i++) ans = ans * (s[vt[i] - 1] + 1) % MOD;
  cout << ans;
}
