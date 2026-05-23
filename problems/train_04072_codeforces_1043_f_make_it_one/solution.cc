#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const int MAX = 300000;
int N, d[MAX + 10], seen[MAX + 10], dp[MAX + 10];
class Choose {
 private:
  vector<int> fac, inv;
  int n, mod;
  void extgcd(int a, int b, int& x, int& y) {
    if (b != 0) {
      extgcd(b, a % b, y, x);
      y = y - (a / b) * x;
    } else {
      x = 1;
      y = 0;
    }
  }

 public:
  Choose(int n, int mod) {
    this->n = n;
    this->mod = mod;
    fac.resize(n + 1);
    inv.resize(n + 1);
    fac[0] = inv[0] = 1;
    int ignore;
    for (int i = 1; i <= n; i++) {
      fac[i] = (int)(((long long)fac[i - 1] * i) % mod);
      extgcd(fac[i], MOD, inv[i], ignore);
      if (inv[i] < 0) inv[i] += MOD;
    }
  }
  int choose(int a, int b) {
    if (0 <= b && b <= a) {
      return (int)(((long long)fac[a] * inv[b] % mod) * inv[a - b] % mod);
    } else {
      return 0;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  cin >> N;
  for (int(i) = 0; (i) < (N); (i)++) {
    int x;
    cin >> x;
    seen[x] = 1;
  }
  for (int i = 1; i <= MAX; i++) {
    for (int j = i; j <= MAX; j += i) {
      if (seen[j]) {
        d[i]++;
      }
    }
  }
  Choose c(MAX, MOD);
  for (int(ans) = 1; (ans) <= (7); (ans)++) {
    for (int j = MAX; j >= 1; j--) {
      dp[j] = c.choose(d[j], ans);
      for (int k = 2; k * j <= MAX; k++) {
        dp[j] += MOD - dp[k * j];
        if (dp[j] >= MOD) dp[j] -= MOD;
      }
    }
    if (dp[1] >= 1) {
      cout << ans << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
