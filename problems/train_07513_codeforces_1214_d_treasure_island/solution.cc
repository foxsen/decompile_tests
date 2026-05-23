#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int ans = 0;
int dfs(int x, int y, string s[], int R, int C) {
  if (x == R || y == C) return 0;
  if (x == R - 1 && y == C - 1) {
    return 1;
  }
  if (s[x][y] == '.') {
    s[x][y] = '#';
    int val = dfs(x, y + 1, s, R, C);
    if (val)
      return val;
    else {
      val = dfs(x + 1, y, s, R, C);
      return val;
    }
  }
  return 0;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n == 1) {
    string x;
    cin >> x;
    int y = 1;
    for (int i = 0; i < m; i++)
      if (x[i] == '#') {
        y = 0;
        break;
      }
    printf("%d\n", y);
  } else if (m == 1) {
    string x;
    int y = 1;
    while (n--) {
      cin >> x;
      if (x[0] == '#') y = 0;
    }
    printf("%d\n", y);
  } else {
    string s[n + 2];
    for (int i = 0; i < n; i++) cin >> s[i];
    int cnt = 0;
    if (s[0][1] == '.') {
      cnt += dfs(0, 1, s, n, m);
    }
    if (s[1][0] == '.') {
      ans = 0;
      cnt += dfs(1, 0, s, n, m);
    }
    printf("%d\n", cnt);
  }
  return 0;
}
