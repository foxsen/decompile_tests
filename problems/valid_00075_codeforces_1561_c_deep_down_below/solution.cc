#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    vector<vector<long long int>> armor;
    vector<pair<long long int, long long int>> inpair(n, {0, 0});
    for (int i = 0; i < n; i++) {
      int caves;
      cin >> caves;
      vector<long long int> vec(caves, 0);
      for (int j = 0; j < caves; j++) {
        cin >> vec[j];
        vec[j] -= j;
      }
      inpair[i].first = *max_element(vec.begin(), vec.end());
      inpair[i].second = caves;
    }
    sort(inpair.begin(), inpair.end());
    long long int powerSum[n];
    powerSum[0] = inpair[0].second;
    for (int i = 1; i < n; i++) {
      powerSum[i] = powerSum[i - 1] + inpair[i].second;
    }
    long long int ans = inpair[0].first + 1;
    for (int i = 1; i < n; i++) {
      ans = max(ans, inpair[i].first - powerSum[i - 1] + 1);
    }
    cout << ans << endl;
  }
  return 0;
}
