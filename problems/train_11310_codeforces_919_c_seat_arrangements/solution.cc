#include <bits/stdc++.h>
using namespace std;
template <class T>
void printQueue(T& q) {
  while (!q.empty()) {
    cout << q.top() << endl;
    q.pop();
  }
}
int main() {
  int t = 1;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int blocks[n + 1][m + 1];
    char c;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> c;
        if (c == '.') {
          blocks[i][j] = 1;
        } else if (c == '*') {
          blocks[i][j] = 0;
        }
      }
    }
    int ans = 0;
    int left[n + 2][m + 2];
    memset(left, 0, sizeof(left));
    int up[n + 2][m + 2];
    memset(up, 0, sizeof(up));
    for (int i = 1; i <= n; i++) {
      for (int j = m; j >= 1; j--) {
        if (blocks[i][j] == 1) {
          left[i][j] = 1 + left[i][j + 1];
        } else {
          left[i][j] = 0;
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = n; j >= 1; j--) {
        if (blocks[j][i] == 1) {
          up[j][i] = 1 + up[j + 1][i];
        } else {
          up[j][i] = 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (k != 1) {
          if (up[i][j] >= k) {
            ans = ans + 1;
          }
          if (left[i][j] >= k) {
            ans = ans + 1;
          }
        } else {
          if (up[i][j] >= 1) {
            ans = ans + 1;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
