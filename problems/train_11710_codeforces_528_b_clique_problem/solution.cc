#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int t, i, j, k, n, m, a, b, c;
  cin >> n;
  set<pair<long long int, long long int> > arr;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    arr.insert(make_pair(a + b, a - b));
  }
  long long int prev = -50000000000ll;
  long long int ans = 0;
  for (__typeof((arr).begin()) X = (arr).begin(); X != (arr).end(); X++) {
    b = X->first;
    a = X->second;
    if (a >= prev) {
      prev = b;
      ans++;
    }
  }
  cout << ans << endl;
}
