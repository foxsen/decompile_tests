#include <bits/stdc++.h>
using namespace std;
long long int po[1005][10];
vector<int> primes;
using ll = long long int;
using dl = double;
int main() {
  ios_base::sync_with_stdio(false);
  string ptr, str, uni;
  ll n, i, j, p, w = 0, ans = 0, a, b, m;
  vector<pair<ll, ll>> vm;
  char ch, ch1, ch2;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    vm.push_back(make_pair(b, a));
    w = w + (b * a);
  }
  sort(vm.begin(), vm.end());
  reverse(vm.begin(), vm.end());
  for (auto it = vm.begin(); it != vm.end(); it++) {
    p = min(n, it->second);
    ans = ans + (p * it->first);
    n = n - p;
    if (n == 0) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << w << endl;
}
