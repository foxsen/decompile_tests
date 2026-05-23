#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int dp[1020][55][55];
string c, a, b;
vector<int> p1, p2;
int m1, m2, n;
vector<int> prefix(string &s) {
  vector<int> pi1(s.size() + 1, -1);
  for (int i = -1, pos = 0; pos < s.size(); pi1[++pos] = ++i) {
    while (i >= 0 && s[i] != s[pos]) i = pi1[i];
  }
  return pi1;
}
int fun(int pos, int ps, int pt) {
  if (pos == n) {
    return 0;
  }
  if (dp[pos][ps][pt] != 1e9) return dp[pos][ps][pt];
  int ans = -1e9;
  int x, y;
  for (char ch = (c[pos] == '*' ? 'a' : c[pos]);
       ch <= (c[pos] == '*' ? 'z' : c[pos]); ch++) {
    for (x = ps; x > -1 && a[x] != ch; x = p1[x])
      ;
    for (y = pt; y > -1 && b[y] != ch; y = p2[y])
      ;
    x++, y++;
    ans = max(ans,
              (x == m1) - (y == m2) +
                  fun(pos + 1, (x == m1) ? p1[x] : x, (y == m2) ? p2[y] : y));
  }
  return dp[pos][ps][pt] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> c >> a >> b;
  for (int i = 0; i < c.size() + 5; i++)
    for (int j = 0; j < a.size() + 4; j++)
      for (int k = 0; k < b.size() + 4; k++) dp[i][j][k] = 1e9;
  n = c.size();
  m1 = a.size();
  m2 = b.size();
  p1 = prefix(a);
  p2 = prefix(b);
  int ans = fun(0, 0, 0);
  cout << ans << endl;
  return 0;
}
