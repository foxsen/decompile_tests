#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() cin.tie(0), ios::sync_with_stdio(false)

using ll = long long;
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while(n > 0) {
    if(n & 1) (res *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return res;
}

int N;

int main() {
  cin >> N;
  vector<int> x(N + 1);
  for(int i = 0; i < N; i++) { cin >> x[i + 1]; }

  ll ans = 0;

  for(int i = 1; i <= N; i++) {
    ans += mod_pow(2, N - i, mod) * x[i] % mod *
           mod_pow(x[i] + 1, i - 1, mod) % mod;
    ans %= mod;
  }
  cout << ans % mod << endl;
}
