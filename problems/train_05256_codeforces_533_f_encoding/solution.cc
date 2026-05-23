#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> ans;
string s, t;
int n, m;
bool f[N][26];
void solve(int a, int b) {
  string str;
  str.clear();
  for (char c : t) {
    if (c - 'a' == a)
      str += c;
    else if (c - 'a' == b)
      str += c;
    else
      str += '.';
  }
  str += '#';
  for (char c : s) {
    if (c - 'a' == a)
      str += b + 'a';
    else if (c - 'a' == b)
      str += a + 'a';
    else
      str += '.';
  }
  vector<int> z(n + m + 1, 0);
  int l = 0;
  int r = 0;
  for (int i = 1; i <= n + m; i++) {
    int &x = z[i];
    if (i <= r) x = min(z[i - l], r - i);
    while (i + x <= n + m && str[x] == str[i + x]) x++;
    if (i + x >= r) {
      l = i;
      r = i + x;
    }
    if (x == m) f[i - m][a] = f[i - m][b] = true;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> s >> t;
  for (int i = 0; i < 26; i++)
    for (int j = i; j < 26; j++) {
      solve(i, j);
    }
  for (int i = 1; i <= n; i++) {
    ans.push_back(i);
    for (int j = 0; j <= 25; j++) {
      if (!f[i][j]) {
        ans.pop_back();
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (int x : ans) cout << x << " ";
  return 0;
}
