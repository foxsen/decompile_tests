#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000;
int N, M, K;
int a[NMAX + 2][NMAX + 2];
struct state {
  int dad, sz;
  int down;
};
state ds[NMAX + 2][NMAX + 2];
bool active[NMAX + 2][NMAX + 2];
int root(int col, int p) {
  if (ds[p][col].dad != p) {
    return ds[p][col].dad = root(col, ds[p][col].dad);
  }
  return p;
}
void join(int col, int p, int q) {
  p = root(col, p);
  q = root(col, q);
  if (ds[p][col].sz > ds[q][col].sz) {
    swap(p, q);
  }
  ds[p][col].dad = q;
  ds[q][col].sz += ds[p][col].sz;
  ds[q][col].down = max(ds[q][col].down, ds[p][col].down);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
      ds[i][j].dad = i;
      ds[i][j].sz = 1;
      ds[i][j].down = i;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (a[i][j] == 2) {
        active[i][j] = true;
        if (active[i - 1][j] == true) {
          join(j, i - 1, i);
        }
      }
    }
  }
  for (int i = 1; i <= K; i++) {
    int x = 1, y;
    cin >> y;
    while (true) {
      if (active[x][y] == true) {
        int r = root(y, x);
        x = ds[r][y].down + 1;
      }
      if (x >= N + 1) {
        cout << y << ' ';
        break;
      }
      int old_x = x, old_y = y;
      if (a[x][y] == 1) {
        y++;
      } else if (a[x][y] == 2) {
        x++;
      } else {
        y--;
      }
      a[old_x][old_y] = 2;
      active[old_x][old_y] = true;
      if (active[old_x - 1][old_y] == true) {
        join(old_y, old_x - 1, old_x);
      }
      if (active[old_x + 1][old_y] == true) {
        join(old_y, old_x + 1, old_x);
      }
    }
  }
  return 0;
}
