// 6/2
// 2-6-4. 素数のこすう
// エラトステネスの篩
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main() {
    // vector<vector<bool>> is_unique(1e6 + 1, vector<bool>(1e6 + 1, true));  // is_unique[i][j] = j / iがユニークかどうか

    // for (int i = 1; i < 1e6; i++) {
    //     for (int j = 1; j < )
    // }

    // Sieve sieve(1e6);

    // vector<int> f(1e6 + 1);  // f[i] = 分母がiの時の項目数

    // f[0] = 0;
    // f[1] = 2;  // 0/1, 1/1

    // for(int i = 2; i <= 1e6; i++) {

    //     vector<P> fact = sieve.factor(i);
    //     ll yakusu = 1;
    //     for (auto f : fact) {
    //         yakusu *= f.second + 1;
    //     }
    //     f[i] = i - yakusu;
    // }

    // vector<int> unique(1e6 + 1);  // unique[i] = 分母がiで約分できない数。ただし0は覗く。

    // rep(i, 1e6 + 1) unique[i] = i;

    // for (int i = 1; i <= 1e6; i++) {
    //     for (int j = i * 2; j <= 1e6; j += i) {
    //         unique[j]--;
    //     }
    // }

    // unique[1] += 1;  // 1の時は0/1があるので特殊。

    // vector<int> ans(1e6 + 1);
    // ans[0] = 0;
    // for(int i = 1; i <= 1e6; i++) {
    //     printf("unique[%d] = %d\n", i, unique[i]);
    //     ans[i] = ans[i - 1] + unique[i];
    // };

    Sieve sieve(1e6);
    vector<ll> F(1e6 + 1);
    F[0] = 0;
    F[1] = 2;
    for (int i = 2; i <= 1e6; i++) {
        vector<P> primes = sieve.factor(i);
        F[i] = i;
        for (auto p : primes) {
            F[i] *= (1.0 - 1.0 / (double)p.first);
        }
    }

    // rep(i, 10) {
    //     printf("F[%d] = %d\n", i, F[i]);
    // }

    vector<ll> ans(1e6 + 1);
    ans[0] = 0;
    for (int i = 1; i <= 1e6; i++) {
        ans[i] = ans[i - 1] + F[i];
    }

    int t;
    cin >> t;

    vector<int> n(t);
    rep(i, t) cin >> n[i];

    rep(i, t) cout << ans[n[i]] << endl;
}
