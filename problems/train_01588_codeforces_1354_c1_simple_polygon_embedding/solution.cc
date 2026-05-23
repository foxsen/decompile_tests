#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m = 1000000007) {
  long long ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1ll * a * ans) % m;
    b >>= 1;
    a = (1ll * a * a) % m;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool cmp(pair<string, int> p1, pair<string, int> p2) {
  return p1.second > p2.second;
}
const int MAXN = 5 * 100000 + 10;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    n *= 2;
    double x = (double)360 / n;
    double y = (double)(180.0 - x) / 2;
    double r = (double)y * ((double)M_PI / 180.0);
    double result = tan(r);
    cout << fixed << setprecision(10) << result << "\n";
  };
}
