#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> candies(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> candies[i];
  };
  sort(candies.begin(), candies.end());
  for (int i = 1; i < n; ++i) {
    candies[i] = k - candies[i];
  }
  long long sum = 0;
  for (int i = 1; i < n; ++i) {
    sum = sum + (candies[i] / candies[0]);
  }
  cout << sum << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
