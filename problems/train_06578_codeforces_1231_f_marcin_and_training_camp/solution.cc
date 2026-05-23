#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> arr[7777];
map<long long int, int> mm;
long long int ans, dp[66];
vector<long long int> v;
int main(void) {
  dp[0] = 1;
  for (int p = 1; p <= 60; p++) dp[p] = dp[p - 1] * 2;
  int n;
  scanf("%d", &n);
  for (int e = 0; e < n; e++) {
    scanf("%lld", &arr[e].first);
    mm[arr[e].first]++;
    if (mm[arr[e].first] == 2) {
      v.push_back(arr[e].first);
    }
  }
  for (int e = 0; e < n; e++) scanf("%lld", &arr[e].second);
  for (int e = 0; e < n; e++) {
    if (mm[arr[e].first] == 1) {
      int tmp = 0;
      for (int p = 0; p < v.size(); p++) {
        int err = 0;
        long long int f1 = v[p], f2 = arr[e].first;
        if ((f1 | f2) == f1) tmp++;
      }
      if (tmp) ans += arr[e].second;
    } else
      ans += arr[e].second;
  }
  printf("%lld", ans);
  return 0;
}
