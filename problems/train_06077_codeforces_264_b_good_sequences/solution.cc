#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  long long divisor[100001] = {-1};
  long long dp[100001] = {0};
  long long max_l = 1;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) continue;
    long long longest = 1;
    long long root = sqrt(a[i]);
    divisor[a[i]] = a[i];
    for (long long j = 2; j < root + 1; j++) {
      if (a[i] % j == 0) {
        if (divisor[j] != (-1)) {
          longest = max(longest, dp[divisor[j]] + 1);
        }
        if (divisor[a[i] / j] != (-1)) {
          longest = max(longest, dp[divisor[a[i] / j]] + 1);
        }
        divisor[j] = a[i];
        divisor[a[i] / j] = a[i];
      }
    }
    dp[a[i]] = longest;
    max_l = max(max_l, longest);
  }
  cout << max_l;
}
