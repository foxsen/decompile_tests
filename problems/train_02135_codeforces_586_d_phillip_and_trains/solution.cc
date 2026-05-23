#include <bits/stdc++.h>
using namespace std;
int n, k, t;
char a[3][200];
bool vis[3][200];
bool check(int x, int y) { return (x >= 0 && y >= 0 && x < 3 && y < 200); }
void solve(int cx, int cy) {
  if (vis[cx][cy]) {
    return;
  }
  vis[cx][cy] = true;
  if (check(cx, cy + 3) && a[cx][cy + 1] == '.' && a[cx][cy + 2] == '.') {
    solve(cx, cy + 3);
  }
  if (check(cx + 1, cy + 3) && a[cx][cy + 1] == '.' &&
      a[cx + 1][cy + 1] == '.' && a[cx + 1][cy + 2] == '.') {
    solve(cx + 1, cy + 3);
  }
  if (check(cx - 1, cy + 3) && a[cx][cy + 1] == '.' &&
      a[cx - 1][cy + 1] == '.' && a[cx - 1][cy + 2] == '.') {
    solve(cx - 1, cy + 3);
  }
}
int main() {
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 200; j++) {
        a[i][j] = '.';
      }
    }
    cin >> n >> k;
    int x, y;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 's') {
          x = i, y = j;
        }
      }
    }
    solve(x, y);
    bool ans = false;
    for (int i = 0; i < 3; i++) {
      for (int j = n - 1; j < 200; j++) {
        ans |= vis[i][j];
      }
    }
    if (ans) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
