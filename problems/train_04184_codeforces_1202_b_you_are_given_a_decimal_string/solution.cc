#include <bits/stdc++.h>
const long long inf = 1e18 + 10;
using namespace std;
string s;
int ans[10][10];
pair<int, int> pre[10][10][10];
void solve(int i, int j) {
  int cnt = 0, cur = 0;
  for (int t = 1; t < s.size(); t++) {
    int pas = s[t] - '0';
    int k = (pas - cur % 10 + 10) % 10;
    if (pre[i][j][k].first == -1) {
      ans[i][j] = ans[j][i] = -1;
      return;
    }
    cur += pre[i][j][k].first * i + pre[i][j][k].second * j;
    cnt += pre[i][j][k].first + pre[i][j][k].second - 1;
  }
  ans[i][j] = ans[j][i] = cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        int f = 0, s = 0, mn = 20;
        for (int x = 0; x < 10; x++) {
          for (int y = 0; y < 10; y++) {
            if (x + y != 0 && (i * x + j * y) % 10 == k && x + y < mn) {
              mn = x + y;
              f = x;
              s = y;
            }
          }
        }
        if (mn == 20) {
          pre[i][j][k] = {-1, -1};
        } else {
          pre[i][j][k] = {f, s};
        }
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = i; j < 10; j++) {
      solve(i, j);
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
