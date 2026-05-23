#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXM = 1000005;
const int MOD = 1000000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int a[1005], color[1005];
int pri[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
vector<int> v[12];
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int j = 0; j < 11; ++j) v[j].clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      for (int j = 0; j < 11; ++j) {
        if (a[i] % pri[j] == 0) {
          color[i] = j;
          v[j].push_back(i);
          break;
        }
      }
    }
    int num[12], tot = 0;
    for (int i = 0; i < 11; ++i) {
      if (v[i].size()) num[i] = ++tot;
    }
    cout << tot << "\n";
    for (int i = 1; i <= n; ++i) cout << num[color[i]] << " ";
    cout << "\n";
  }
  return 0;
}
