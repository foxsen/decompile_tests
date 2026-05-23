#include <bits/stdc++.h>
using namespace std;
long long n, x;
multiset<long long> sets;
vector<long long> v(200200);
long long ans = 0;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> v[i];
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> x;
    ans = 0;
    while (!sets.empty() && *sets.begin() - sum <= x) {
      ans += (*sets.begin() - sum);
      sets.erase(sets.begin());
    }
    if (v[i] <= x)
      ans += v[i];
    else
      sets.insert(v[i] + sum);
    sum += x;
    cout << ((long long)sets.size() * x) + ans << " ";
  }
  return 0;
}
