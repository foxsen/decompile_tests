#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  ;
  string str;
  cin >> str;
  ;
  map<long long, long long> mp;
  mp[0] = 1;
  long long sum = 0;
  long long ans = 0;
  for (long long i = 0; i < str.size(); i++) {
    sum += (str[i] - '0') - 1;
    ans += mp[sum];
    mp[sum]++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
