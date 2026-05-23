#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, INF = 1e18, mx = 1e5 + 5, mn = 100;
int testCase = 1, cas = 0;
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  while (testCase--) {
    map<int, int> P;
    int n;
    cin >> n;
    int ar[n + 4], br[n + 5];
    for (int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> br[i];
    }
    vector<pair<int, int> > Ans;
    for (int i = 1; i <= n; i++) {
      if (ar[i] == br[i]) continue;
      int j;
      for (j = i + 1; j <= n; j++) {
        if (ar[i] == br[j]) break;
      }
      while (j > i) {
        swap(br[j - 1], br[j]);
        Ans.push_back({j - 1, j});
        j--;
      }
    }
    cout << Ans.size() << endl;
    for (int i = 0; i < Ans.size(); i++)
      cout << Ans[i].first << " " << Ans[i].second << endl;
  }
  return 0;
}
