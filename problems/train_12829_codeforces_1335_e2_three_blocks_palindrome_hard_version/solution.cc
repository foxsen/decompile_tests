#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int inf = 1e18;
int m_inf = INT_MIN;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout.unsetf(std::ios::floatfield);
  std::cout.precision(15);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int> > freq(n, vector<int>(201, 0));
    vector<vector<int> > pos(201);
    freq[0][arr[0]] = 1;
    pos[arr[0]].push_back(0);
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < 201; j++) {
        if (arr[i] == j) {
          freq[i][arr[i]] = freq[i - 1][arr[i]] + 1;
          pos[j].push_back(i);
        } else
          freq[i][j] = freq[i - 1][j];
      }
    }
    int ans = 1;
    for (int i = 1; i < 201; i++) {
      for (int j = 0; j < pos[i].size() / 2; j++) {
        int l = pos[i][j], r = pos[i][pos[i].size() - 1 - j];
        int cor = j + 1;
        int mid = 0;
        for (int k = 1; k <= 200; k++) {
          mid = max(mid, freq[r - 1][k] - freq[l][k]);
        }
        ans = max(ans, 2 * cor + mid);
      }
    }
    cout << ans << '\n';
  }
}
