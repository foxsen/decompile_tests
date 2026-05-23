#include <bits/stdc++.h>
using namespace std;
void test() {
  string s;
  cin >> s;
  42;
  int n;
  n = s.size();
  vector<pair<int, string>> ans;
  string cur = "";
  vector<pair<int, pair<char, char>>> history;
  auto add = [&]() {
    if (cur.size() > 10) {
      string temp = "";
      for (int i = 0; i < 2; ++i) {
        temp += cur[i];
      }
      temp += "...";
      for (int i = cur.size() - 5; i < cur.size(); ++i) {
        temp += cur[i];
      }
      ans.emplace_back(cur.size(), temp);
    } else {
      ans.emplace_back(cur.size(), cur);
    }
  };
  for (int i = n - 1; i >= 0; --i) {
    if (!cur.size()) {
      pair<char, char> pr = {s[i], 'A'};
      cur += s[i];
      history.emplace_back(i, pr);
    } else if (s[i] != cur.back()) {
      pair<char, char> pr = {s[i], cur.back()};
      cur += s[i];
      history.emplace_back(i, pr);
    } else if (history.back().first == i + 1 and
               s[i] > history.back().second.second) {
      cur.pop_back();
      history.pop_back();
    } else {
      pair<char, char> pr = history.back().second;
      42;
      cur += s[i];
      history.emplace_back(i, pr);
    }
    add();
  }
  reverse(ans.begin(), ans.end());
  for (auto &x : ans) {
    reverse(x.second.begin(), x.second.end());
    cout << x.first << " " << x.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    test();
  }
  return 0;
}
