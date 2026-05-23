#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int ri() {
  int x;
  cin >> x;
  return x;
}
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (T &x : a) in >> x;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (T &x : a) out << x << ' ';
  return out;
}
const ll modd = 998244353;
const ll mod = 1e9 + 7;
const ll MX = 1e14;
const int N = 1e6 + 1;
const int inf = INT_MAX;
const ll inff = numeric_limits<ll>::max();
const int NMAX = 2e5 + 3;
const int nmax = 1e3 + 2;
void solve() {
  int n, m;
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  int s1, s2;
  cin >> s1 >> s2;
  int x1 = 1, y1 = 1;
  int ans = 0;
  while (1) {
    if (x + x1 == 0 || x + x1 == n + 1) x1 = -x1;
    if (y + y1 == 0 || y + y1 == m + 1) y1 = -y1;
    if (s1 == x || s2 == y) break;
    x += x1;
    y += y1;
    if (x + x1 == 0 || x + x1 == n + 1) x1 = -x1;
    if (y + y1 == 0 || y + y1 == m + 1) y1 = -y1;
    ans++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int q = ri(); q--; cout << '\n') solve();
}
