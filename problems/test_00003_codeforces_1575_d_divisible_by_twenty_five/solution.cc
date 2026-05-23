#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
const int M = 25;
string s;
bool check() {
  int res = 0;
  if (s[0] == '0') return false;
  for (auto c : s) {
    res = res * 10 + c - '0';
  }
  return res != 0 && res % 25 == 0;
}
int dfs(int p, char x) {
  if (p >= s.length()) return check();
  if (s[p] == 'X') {
    s[p] = x;
    int ans = dfs(p + 1, x);
    s[p] = 'X';
    return ans;
  } else if (s[p] == '_') {
    int ans = 0;
    for (char i = '0'; i <= '9'; ++i) {
      s[p] = i;
      ans += dfs(p + 1, x);
    }
    s[p] = '_';
    return ans;
  } else {
    return dfs(p + 1, x);
  }
}
void solve() {
  cin >> s;
  if (s.length() < 2) {
    if (s == "0" || s == "X" || s == "_")
      puts("1");
    else
      puts("0");
    return;
  }
  int ans = 0;
  if (s.find('X') != -1) {
    for (char x = '0'; x <= '9'; ++x) {
      ans += dfs(0, x);
    }
  } else {
    ans = dfs(0, '0');
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
