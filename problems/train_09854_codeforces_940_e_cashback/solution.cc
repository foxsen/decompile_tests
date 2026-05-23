#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, c;
  cin >> n >> c;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  if (c == 1) {
    cout << 0;
    return 0;
  }
  long long dp[n];
  for (long long i = 0; i < n; i++) dp[i] = 10000000000000000;
  dp[0] = arr[0];
  map<long long, long long> ma;
  ma[arr[0]] = 1;
  long long sum = arr[0];
  for (long long i = 1; i < n; i++) {
    sum += arr[i];
    ma[arr[i]]++;
    if (i == c - 1) {
      dp[i] = min(dp[i], sum - (ma.begin())->first);
    }
    if (i >= c) {
      sum -= arr[i - c];
      ma[arr[i - c]]--;
      if (ma[arr[i - c]] == 0) ma.erase(arr[i - c]);
      long long temp = sum - (ma.begin())->first;
      dp[i] = min(dp[i], dp[i - c] + temp);
    }
    dp[i] = min(dp[i - 1] + arr[i], dp[i]);
  }
  cout << dp[n - 1];
  return 0;
}
