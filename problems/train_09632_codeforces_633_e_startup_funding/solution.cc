#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
const double pi = acos(-1.0);
vector<vector<int> > sv, sc;
int n, k;
int queryv(int l, int r) {
  while (r >= n) {
    r--;
  }
  int p = 0;
  while ((1 << (p + 1)) <= (r - l + 1)) {
    p++;
  }
  return max(sv[l][p], sv[r - (1 << p) + 1][p]);
}
int queryc(int l, int r) {
  while (r >= n) r--;
  int p = 0;
  while ((1 << (p + 1)) <= (r - l + 1)) {
    p++;
  }
  return min(sc[l][p], sc[r - (1 << p) + 1][p]);
}
int main() {
  cin >> n >> k;
  vector<int> v, c;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x *= 100;
    v.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    c.push_back(x);
  }
  sv.assign(n + 10, vector<int>(21, 0));
  sc = sv;
  for (int j = 0; (1 << j) <= n; j++) {
    for (int i = 0; i < n; i++) {
      if (j == 0) {
        sv[i][j] = v[i];
        sc[i][j] = c[i];
      } else {
        if (i + (1 << j) <= n) {
          sv[i][j] = max(sv[i][j - 1], sv[i + (1 << (j - 1))][j - 1]);
          sc[i][j] = min(sc[i][j - 1], sc[i + (1 << (j - 1))][j - 1]);
        } else {
          break;
        }
      }
    }
  }
  vector<int> dp(n, 0);
  for (int l = 0; l < n; l++) {
    int low = l;
    int high = n - 1;
    int mid;
    int ans = l;
    while (low <= high) {
      mid = (low + high) / 2;
      if (queryv(l, mid) <= queryc(l, mid)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    dp[l] = max(min(queryv(l, ans), queryc(l, ans)),
                min(queryv(l, ans + 1), queryc(l, ans + 1)));
  }
  sort(dp.begin(), dp.end());
  long double ans = 0.0;
  long double rat = (long double)k / n;
  for (int i = 0; i + k - 1 < n; i++) {
    long double val = (long double)dp[i];
    ans += val * rat;
    rat = rat * (n - k - i) / (n - i - 1);
  }
  cout << setprecision(20) << fixed;
  cout << ans << endl;
  return 0;
}
