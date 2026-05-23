#include <bits/stdc++.h>
using namespace std;
const int N = 20;
bool st[N][N];
string s[N];
struct Node {
  int l, r;
};
void Test() {
  memset(st, 0, sizeof st);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<Node> v;
      if (s[i][j] != '*') continue;
      int cnt = 0;
      int ans = 1;
      while (1) {
        if (i - ans < 0 || j - ans < 0 || j + ans >= m) break;
        if (s[i - ans][j - ans] != '*' || s[i - ans][j + ans] != '*') break;
        v.push_back({i - ans, j - ans});
        v.push_back({i - ans, j + ans});
        ans++;
      }
      if (ans - 1 < k) continue;
      st[i][j] = 1;
      int len = v.size();
      for (int i = 0; i < len; i++) st[v[i].l][v[i].r] = 1;
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*' && st[i][j] == 0) flag = 1;
  }
  if (flag)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) Test();
}
