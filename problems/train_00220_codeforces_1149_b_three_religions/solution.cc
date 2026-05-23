#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
double get_time() { return 1.0 * clock() / CLOCKS_PER_SEC; }
int main() {
  fast();
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> nxt(26, vector<int>(n + 2, n + 1));
  for (int i = n - 1; i >= 0; i--) {
    nxt[s[i] - 'a'][i] = i;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = n - 1; j >= 0; j--) nxt[i][j] = min(nxt[i][j], nxt[i][j + 1]);
  }
  vector<vector<vector<int>>> dp(
      256, vector<vector<int>>(256, vector<int>(256, n + 1)));
  dp[0][0][0] = 0;
  vector<int> l(3);
  vector<string> t(3, "");
  while (q--) {
    char ch, c;
    int idx;
    cin >> ch >> idx;
    idx--;
    if (ch == '+') {
      cin >> c;
      l[idx]++;
      t[idx] += c;
    }
    42;
    int lim0 = (idx == 0 ? l[0] : 0);
    int lim1 = (idx == 1 ? l[1] : 0);
    int lim2 = (idx == 2 ? l[2] : 0);
    for (int i = lim0; i <= l[0]; i++) {
      for (int j = lim1; j <= l[1]; j++) {
        for (int k = lim2; k <= l[2]; k++) {
          dp[i][j][k] = n + 1;
          if (ch == '+') {
            if (i > 0)
              dp[i][j][k] =
                  min(dp[i][j][k], nxt[t[0][i - 1] - 'a'][dp[i - 1][j][k]] + 1);
            if (j > 0)
              dp[i][j][k] =
                  min(dp[i][j][k], nxt[t[1][j - 1] - 'a'][dp[i][j - 1][k]] + 1);
            if (k > 0)
              dp[i][j][k] =
                  min(dp[i][j][k], nxt[t[2][k - 1] - 'a'][dp[i][j][k - 1]] + 1);
          }
        }
      }
    }
    if (ch == '-') {
      l[idx]--;
      t[idx] = t[idx].substr(0, (int)t[idx].size() - 1);
    }
    if (dp[l[0]][l[1]][l[2]] < n + 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
