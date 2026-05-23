#include <bits/stdc++.h>
using namespace std;
vector<long long> fact;
void precalc(long long n) {
  fact.resize(n / 2 + 1);
  fact[0] = 1;
  for (long long i = 1; i < fact.size(); ++i) {
    fact[i] = fact[i - 1] * i % 1000000007;
  }
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % 1000000007;
    }
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
long long divis(long long a, long long b) {
  return a * binpow(b, 1000000007 - 2) % 1000000007;
}
long long fun(long long a, long long b) {
  return divis(divis(fact[a], fact[b]), fact[a - b]);
}
void solve() {
  long long Q;
  Q = 1;
  while (Q--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    ;
    precalc(n);
    vector<long long> b(n);
    if (n % 4 == 0) {
      for (long long i = 0, cnt = 1; i < n; ++i, cnt = -cnt) {
        b[i] = fun((n - 2) / 2, i / 2) * cnt;
      }
    } else if (n % 4 == 1) {
      for (long long i = 0; i < n; ++i) {
        if (i % 2 == 0) {
          b[i] = fun((n - 1) / 2, i / 2);
        } else {
          b[i] = 0;
        }
      }
    } else if (n % 4 == 2) {
      for (long long i = 0; i < n; ++i) {
        b[i] = fun((n - 2) / 2, i / 2);
      }
    } else {
      b[0] = 1;
      b[n - 1] = 1000000007 - 1;
      for (long long i = 1; i < n - 1; ++i) {
        if (i % 2 == 0) {
          b[i] = (fun((n - 3) / 2, i / 2) - fun((n - 3) / 2, i / 2 - 1) +
                  1000000007) %
                 1000000007;
        } else {
          b[i] = 2 * fun((n - 3) / 2, i / 2) % 1000000007;
        }
      }
    }
    long long res = 0;
    for (long long i = 0; i < n; ++i) {
      res = (res + a[i] * b[i]) % 1000000007;
    }
    cout << (res + 1000000007) % 1000000007;
  }
}
signed main(signed argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && (string)argv[1] == "local") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    while (cin.peek() != EOF) {
      if (isspace(cin.peek()))
        cin.get();
      else {
        cout << '\n';
        solve();
      }
    }
  } else {
    solve();
  }
}
