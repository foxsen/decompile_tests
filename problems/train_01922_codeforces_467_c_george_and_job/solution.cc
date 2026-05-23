#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
const int mod = 1e9 + 7;
long long ans;
long long n, m, k;
long long a[N];
long long d[N][N];
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  long long y = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = m; j <= n; j++) {
      d[i][j] = max(d[i][j - 1], a[j] - a[j - m] + d[i - 1][j - m]);
    }
  }
  cout << d[k][n];
}
