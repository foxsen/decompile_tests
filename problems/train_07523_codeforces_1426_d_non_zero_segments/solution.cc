#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; i++) cin >> v[i];
  long long ans = 0, s = 0;
  map<long long, long long> m;
  m[0]++;
  for (long long i = 1; i <= n; i++) {
    s += v[i];
    if (m.find(s) != m.end()) {
      ans += 1;
      s = v[i];
      m.clear();
      m[0]++;
      m[s]++;
    } else {
      m[s]++;
    }
  }
  cout << ans << endl;
  return 0;
}
