#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100, maxc = 115, inf = 1e9 + 10;
long long t, n, f[100], dp1[100], dp2[100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  f[0] = f[1] = 1;
  for (int i = 2; f[i - 1] < (long long)1e18; i++) f[i] = f[i - 1] + f[i - 2];
  cin >> t;
  while (t--) {
    int k = 0;
    cin >> n;
    vector<int> v;
    v.clear();
    for (int i = 90; i > 0 && n > 0; i--)
      if (n >= f[i] && f[i] > 0) v.push_back(i), n -= f[i], k++;
    v.push_back(0);
    reverse(v.begin(), v.end());
    dp1[0] = 1;
    dp2[0] = 0;
    for (int i = 1; i <= k; i++) {
      dp1[i] = dp1[i - 1] + dp2[i - 1];
      dp2[i] = dp1[i - 1] * ((v[i] - v[i - 1] - 1) / 2) +
               dp2[i - 1] * ((v[i] - v[i - 1]) / 2);
    }
    cout << dp1[k] + dp2[k] << endl;
  }
  return 0;
}
