#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    vector<int> temp;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '<')
        temp.push_back(n - i);
      else {
        if (!temp.empty()) {
          temp.push_back(n - i);
          reverse(temp.begin(), temp.end());
          for (auto it : temp) ans.push_back(it);
          temp.clear();
        } else
          ans.push_back(n - i);
      }
    }
    if (s[n - 2] == '<') {
      temp.push_back(1);
      reverse(temp.begin(), temp.end());
      for (auto it : temp) ans.push_back(it);
      temp.clear();
    } else {
      if (!temp.empty()) {
        reverse(temp.begin(), temp.end());
        for (auto it : temp) ans.push_back(it);
        temp.clear();
      }
      ans.push_back(1);
    }
    for (int i = 0; i < n; i++) {
      if (!i)
        cout << ans[i];
      else
        cout << " " << ans[i];
    }
    cout << "\n";
    ans.clear();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '>')
        temp.push_back(i + 1);
      else {
        if (!temp.empty()) {
          temp.push_back(i + 1);
          reverse(temp.begin(), temp.end());
          for (auto it : temp) ans.push_back(it);
          temp.clear();
        } else
          ans.push_back(i + 1);
      }
    }
    if (s[n - 2] == '>') {
      temp.push_back(n);
      reverse(temp.begin(), temp.end());
      for (auto it : temp) ans.push_back(it);
      temp.clear();
    } else {
      if (!temp.empty()) {
        reverse(temp.begin(), temp.end());
        for (auto it : temp) ans.push_back(it);
        temp.clear();
      }
      ans.push_back(n);
    }
    for (int i = 0; i < n; i++) {
      if (!i)
        cout << ans[i];
      else
        cout << " " << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
