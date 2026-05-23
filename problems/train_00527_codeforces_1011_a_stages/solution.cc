#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  string ans;
  ans += s[0];
  k--;
  for (int i = 1; i < s.length() && k > 0; i++) {
    if (k > 0 && s[i] - ans[ans.length() - 1] > 1) {
      ans += s[i];
      k--;
    }
  }
  if (k == 0) {
    int count = 0;
    for (int i = 0; i < ans.length(); i++) {
      count += ans[i] - 96;
    }
    cout << count << '\n';
  } else
    cout << "-1\n";
}
