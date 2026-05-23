#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> check(ll n) {
  vector<ll> f;
  ll i, m;
  m = n;
  for (i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      f.push_back(i);
    }
  }
  if ((n > 1) && (n != m)) f.push_back(n);
  if (f.empty()) return {1, 0};
  if (f.size() > 2) return {1, f[0] * f[1]};
  return {2, 0};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  auto p = check(n);
  if (p.first == 1)
    cout << "1\n" << p.second;
  else
    cout << "2";
  return 0;
}
