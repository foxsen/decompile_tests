#include <bits/stdc++.h>
using namespace std;
char maze[110][110];
struct node {
  int x, y;
  int cnt;
} ans;
int n, k;
int cal(int x, int y) {
  int res = 0;
  for (int i = y - k + 1; i <= y; i++) {
    if (i < 0) continue;
    bool flag = true;
    for (int j = i; j <= (i + k - 1); j++) {
      if (j >= n) {
        flag = false;
        break;
      }
      if (maze[x][j] != '.') {
        flag = false;
        break;
      }
    }
    if (flag) res++;
  }
  for (int i = x - k + 1; i <= x; i++) {
    if (i < 0) continue;
    bool flag = true;
    for (int j = i; j <= i + k - 1; j++) {
      if (j >= n) {
        flag = false;
        break;
      }
      if (maze[j][y] != '.') {
        flag = false;
        break;
      }
    }
    if (flag) res++;
  }
  return res;
}
int main() {
  ans.cnt = 0;
  ans.x = ans.y = -1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> maze[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (maze[i][j] == '.') {
        int tmp = cal(i, j);
        if (tmp > ans.cnt) {
          ans.cnt = tmp;
          ans.x = i;
          ans.y = j;
        }
      }
    }
  }
  if (ans.cnt == 0) {
    cout << 1 << " " << 1 << endl;
  } else {
    cout << ans.x + 1 << " " << ans.y + 1 << endl;
  }
  return 0;
}
