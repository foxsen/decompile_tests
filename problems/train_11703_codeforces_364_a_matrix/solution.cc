#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[40000];
std::map<long long, long long> freq;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  cin >> a;
  string second;
  cin >> second;
  for (int i = 0; i < second.length(); ++i) {
    dp[i + 1] = second[i] - '0';
    dp[i + 1] += dp[i];
  }
  for (int i = 1; i <= second.length(); ++i) {
    for (int j = i; j <= second.length(); ++j) {
      freq[dp[j] - dp[i - 1]]++;
    }
  }
  long long ans = 0;
  if (a == 0) {
    for (int i = 0; i <= 40000; ++i) {
      ans += freq[0] * 1LL * freq[i];
    }
  }
  for (int i = 1; i <= 40000; ++i) {
    if (a % i == 0) {
      ans += freq[i] * 1LL * freq[(int)a / i];
    }
  }
  cout << ans;
  return 0;
}
