#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  map<long long, long long> m;
  long long psum[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      if (arr[i] >= 0)
        psum[i] = arr[i];
      else
        psum[i] = 0;
    } else {
      if (arr[i] >= 0)
        psum[i] = arr[i] + psum[i - 1];
      else
        psum[i] = psum[i - 1];
    }
  }
  long long res = -1e18;
  pair<long long, long long> index;
  for (int i = 0; i < n; i++) {
    if (m.find(arr[i]) != m.end()) {
      long long sum = psum[i];
      if (arr[i] < 0) {
        sum += 2 * arr[i];
        sum -= psum[m[arr[i]]];
      } else {
        if (m[arr[i]] > 0) sum -= psum[m[arr[i]] - 1];
      }
      if (res <= sum) {
        res = sum;
        index.first = m[arr[i]];
        index.second = i;
      }
    } else {
      m[arr[i]] = i;
    }
  }
  cout << res << " ";
  vector<long long> k;
  for (int i = 0; i < n; i++) {
    if (i < index.first or i > index.second)
      k.push_back(i + 1);
    else if (i > index.first and i < index.second and arr[i] < 0)
      k.push_back(i + 1);
  }
  cout << k.size() << "\n";
  for (auto x : k) cout << x << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
