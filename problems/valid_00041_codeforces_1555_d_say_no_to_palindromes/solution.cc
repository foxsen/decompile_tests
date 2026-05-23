#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e17 + 11;
const int N = 2e5 + 11;
vector<string> patterns;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = " " + s;
  vector<vector<int> > f(6, vector<int>(n + 1, 0));
  for (int i = 0; i < 6; i++)
    for (int j = 1; j <= n; j++)
      f[i][j] = f[i][j - 1] + (s[j] != patterns[i][(j - 1) % 3]);
  while (m--) {
    int l, r;
    cin >> l >> r;
    int answer = 123456789;
    for (int i = 0; i < 6; i++) answer = min(answer, f[i][r] - f[i][l - 1]);
    cout << answer << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  patterns.push_back("abc");
  patterns.push_back("acb");
  patterns.push_back("bac");
  patterns.push_back("bca");
  patterns.push_back("cab");
  patterns.push_back("cba");
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
