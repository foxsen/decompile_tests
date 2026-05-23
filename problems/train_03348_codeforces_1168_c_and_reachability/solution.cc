#include <bits/stdc++.h>
const long long mod1 = (long long)1e9 + 7;
const long long mod2 = (long long)1e9 + 9;
const long long BASE = 15879;
const long long inf = (long long)1e18;
const long double e = 2.718281828459;
const long double pi = 3.141592653;
const long double EPS = 1e-9;
using namespace std;
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &cnt : arr) {
    in >> cnt;
  }
  return in;
};
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<long long> arr(n);
  cin >> arr;
  long long B = 20;
  vector<vector<long long>> dp(n, vector<long long>(B, inf));
  vector<long long> nxt(B, -1);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < B; j++) {
      if (nxt[j] != -1 and (arr[i] & (1 << j)) != 0) {
        for (int k = 0; k < B; k++) {
          dp[i][k] = min(dp[nxt[j]][k], dp[i][k]);
          if (arr[nxt[j]] & (1 << k)) {
            dp[i][k] = min(dp[i][k], nxt[j]);
          }
        }
      }
      if (arr[i] & (1 << j)) {
        nxt[j] = i;
      }
    }
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    bool ans = false;
    for (int i = 0; i < B; i++) {
      if (arr[y] & (1 << i)) {
        ans |= dp[x][i] <= y;
      }
    }
    if (ans) {
      cout << "Shi\n";
    } else {
      cout << "Fou\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(30);
  long long seed = time(0);
  srand(seed);
  solve();
  return 0;
}
