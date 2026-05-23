#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();
constexpr double PI = 3.1415926535897932384626433832795028841971;
void solve() {
  int Q;
  cin >> Q;
  cout << setprecision(20);
  while (Q--) {
    double N;
    cin >> N;
    double phi = 0;
    ll cnt = 0;
    while (phi < PI / 4.0) {
      phi += PI / N;
      ++cnt;
    }
    double z = PI / (2.0 * N) + PI / N * (N / 2 - cnt);
    double th = PI / 4.0 - z;
    double ans = cos(th) / sin(PI / (2.0 * N));
    cout << ans << "\n";
  }
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  solve();
  cout << flush;
  return 0;
}
