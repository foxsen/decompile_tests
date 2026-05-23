#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
      if (s1[i] != s2[i]) {
        if (s1[0] == s2[i]) {
          ans.push_back(0);
          if (s1[0] == '0')
            s1[0] = '1';
          else
            s1[0] = '0';
        }
        ans.push_back(i);
        for (int j = 0; j <= i; j++) {
          if (s1[j] == '0')
            s1[j] = '1';
          else
            s1[j] = '0';
        }
        reverse(s1.begin(), s1.begin() + i + 1);
      }
    }
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
    cout << endl;
  }
  return 0;
}
