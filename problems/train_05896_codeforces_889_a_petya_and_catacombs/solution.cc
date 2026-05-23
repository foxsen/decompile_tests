#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    long long n, i;
    cin >> n;
    map<long long, long long> mp;
    long long s = 0;
    for (i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      mp[x]++;
    }
    for (auto i : mp) {
      if (i.first == 0)
        s += i.second;
      else
        s += i.second - 1;
    }
    cout << s << endl;
  }
  return 0;
}
