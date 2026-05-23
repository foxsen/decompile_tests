#include <bits/stdc++.h>
using namespace std;
const long long infl = 1LL << 60;
int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> v;
    long long ans = 1, x = 1;
    while (ans <= n) {
      v.push_back(x);
      x = x * 2;
      ans += x;
    }
    if (ans > n && x + n != ans) {
      v.push_back(x - ans + n);
    }
    ans = 1;
    for (int i = 0; i < v.size(); i++) {
      ans = (ans * (v[i] + 1)) % m;
    }
    ans--;
    cout << (ans + m) % m << endl;
  }
  return 0;
}
