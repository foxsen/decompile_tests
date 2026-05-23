#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long mas[maxn] = {0};
long long a[maxn];
long long mean[maxn] = {0};
long long ask[maxn][3];
long long ans[maxn] = {0};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> ask[i][0] >> ask[i][1] >> ask[i][2];
  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    mas[l]++;
    mas[r + 1]--;
    continue;
  }
  for (int i = 1; i <= m; i++) mas[i] += mas[i - 1];
  for (int i = 1; i <= m; i++) {
    ans[ask[i][0]] += ask[i][2] * mas[i];
    ans[ask[i][1] + 1] -= ask[i][2] * mas[i];
    continue;
  }
  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    cout << a[i] + ans[i] << " ";
    continue;
  }
  cout << endl;
  return 0;
}
