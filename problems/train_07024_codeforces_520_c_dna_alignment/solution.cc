#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, mx = 0, po = 0;
  cin >> n;
  string s;
  cin >> s;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[s[i]]++;
    if (mp[s[i]] > mx)
      mx = mp[s[i]], po = 1;
    else if (mp[s[i]] == mx)
      po++;
  }
  long long int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = (ans * po) % MOD;
  }
  cout << ans << endl;
  return 0;
}
