#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = acos(-1);
const ll N = 1600000;
ll bor[N * 2][2], cnt = 1;
ll temp[N * 2];
void add(ll n) {
  ll x = 0;
  for (ll bit = 30; bit > -1; bit--) {
    ll y = ((n >> bit) & 1);
    if (bor[x][y] == 0) {
      bor[x][y] = cnt;
      cnt++;
    }
    temp[x]++;
    x = bor[x][y];
  }
  temp[x]++;
}
void del(ll n) {
  ll x = 0;
  for (ll bit = 30; bit > -1; bit--) {
    ll y = ((n >> bit) & 1);
    temp[x]--;
    x = bor[x][y];
  }
  temp[x]--;
}
void XoR(ll n) {
  ll x = 0, mx = 0, bin = 1073741824;
  for (ll bit = 30; bit > -1; bit--) {
    ll y = ((n >> bit) & 1);
    if (bor[x][abs(y - 1)] != 0 and temp[bor[x][abs(y - 1)]] > 0)
      mx += bin, x = bor[x][abs(y - 1)];
    else if (bor[x][y] != 0 and temp[bor[x][y]] > 0)
      x = bor[x][y];
    else
      break;
    bin /= 2;
  }
  cout << mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ll n;
  cin >> n;
  add(0);
  for (ll i = 0; i < n; i++) {
    char d;
    ll a;
    cin >> d >> a;
    if (d == '+') add(a);
    if (d == '-') del(a);
    if (d == '?') XoR(a);
  }
  return 0;
}
