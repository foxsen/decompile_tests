#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> vect;
    map<int, int> mp1;
    map<int, int> mp2;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      vect.push_back({a, b});
      mp1[a]++;
      mp2[b]++;
    }
    long long int ans = round(n * 1LL * (n - 1) / 6.0 * (n - 2));
    for (int i = 0; i < n; i++) {
      long long int ta = mp1[vect[i].first] - 1;
      long long int tb = mp2[vect[i].second] - 1;
      ans -= ta * 1LL * tb;
    }
    cout << ans << endl;
  }
}
