#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios::badbit | ios::failbit);
  long long A;
  cin >> A;
  vector<long long> divs;
  vector<int> isolatable;
  vector<long long> rep_p;
  vector<vector<int>> ddivs;
  for (auto low = 1LL, d = 1LL; low <= A; low = d + 1) {
    d = A / (A / low);
    if (A % d == 0) {
      divs.push_back(d);
      ddivs.emplace_back();
      for (auto i = 0; i < (int)divs.size(); ++i) {
        if (d % divs[i] == 0) {
          ddivs.back().push_back(i);
        }
      }
      42;
      if (d <= 2) {
        isolatable.push_back(false);
        rep_p.push_back(-1);
      } else {
        long long x = d - 1, p = -1;
        for (auto q = 2LL; q * q <= x; ++q) {
          if (x % q == 0) {
            p = q;
            break;
          }
        }
        if (!~p) {
          p = x;
        }
        rep_p.push_back(p);
        while (x % p == 0) {
          x /= p;
        }
        isolatable.push_back(x == 1);
      }
    }
  }
  42;
  42;
  vector<long long> primes = rep_p;
  sort(primes.begin(), primes.end()),
      primes.erase(unique(primes.begin(), primes.end()), primes.end());
  if (!primes.empty() && !~primes[0]) primes.erase(primes.begin());
  for (auto &p : rep_p) {
    if (~p) {
      p = lower_bound(primes.begin(), primes.end(), p) - primes.begin();
    }
  }
  42;
  int np = (int)primes.size(), n = (int)divs.size();
  vector<vector<long long>> dp(n, vector<long long>(np + 1));
  fill(dp[0].begin(), dp[0].end(), 1);
  for (auto i = 1; i < n; ++i) {
    for (auto t = 1; t < (int)ddivs[i].size(); ++t) {
      int j = ddivs[i][t], k = ddivs[i][(int)ddivs[i].size() - 1 - t];
      if (isolatable[j]) {
        int p = rep_p[j];
        dp[i][p + 1] += dp[k][p];
      }
    }
    for (auto p = 0; p < np; ++p) {
      dp[i][p + 1] += dp[i][p];
    }
  }
  42;
  cout << dp[n - 1][np] << "\n";
  return 0;
}
