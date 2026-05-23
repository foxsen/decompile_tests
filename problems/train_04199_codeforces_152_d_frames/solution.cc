#include <bits/stdc++.h>
using namespace std;
char field[1000][1001];
pair<int, int> a[8000];
int axisX[1000], axisY[1000];
bool check(int x1, int y1, int x2, int y2) {
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  if (x2 - x1 < 2 || y2 - y1 < 2) return false;
  for (int i = x1; i <= x2; i++) {
    if (field[i][y1] != '#') return false;
    if (field[i][y2] != '#') return false;
  }
  for (int j = y1; j <= y2; j++) {
    if (field[x1][j] != '#') return false;
    if (field[x2][j] != '#') return false;
  }
  return true;
}
void judge(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
           int cnt) {
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  if (x3 > x4) swap(x3, x4);
  if (y3 > y4) swap(y3, y4);
  if (!check(x1, y1, x2, y2)) return;
  if (!check(x3, y3, x4, y4)) return;
  for (int i = 0; i < cnt; i++) {
    bool flag = false;
    int x = a[i].first, y = a[i].second;
    if (x == x1 && y1 <= y && y <= y2) flag = true;
    if (x == x2 && y1 <= y && y <= y2) flag = true;
    if (y == y1 && x1 <= x && x <= x2) flag = true;
    if (y == y2 && x1 <= x && x <= x2) flag = true;
    if (x == x3 && y3 <= y && y <= y4) flag = true;
    if (x == x4 && y3 <= y && y <= y4) flag = true;
    if (y == y3 && x3 <= x && x <= x4) flag = true;
    if (y == y4 && x3 <= x && x <= x4) flag = true;
    if (!flag) return;
  }
  printf("YES\n");
  printf("%d %d %d %d\n", min(x1, x2) + 1, min(y1, y2) + 1, max(x1, x2) + 1,
         max(y1, y2) + 1);
  printf("%d %d %d %d\n", min(x3, x4) + 1, min(y3, y4) + 1, max(x3, x4) + 1,
         max(y3, y4) + 1);
  exit(0);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", field[i]);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (field[i][j] == '#') cnt++;
  if (cnt == 0 || cnt > 4 * (n + m) - 8) {
    printf("NO\n");
    return 0;
  }
  int tmp = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (field[i][j] == '#') a[tmp++] = make_pair(i, j);
  int upperX = -1, upperY = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (field[i][j] == '#' && upperX == -1) {
        upperX = i;
        upperY = j;
      }
  int lowerX = -1, lowerY = -1;
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      if (field[i][j] == '#' && lowerX == -1) {
        lowerX = i;
        lowerY = j;
      }
  judge(upperX, upperY, lowerX - 1, lowerY, upperX + 1, upperY, lowerX, lowerY,
        cnt);
  judge(upperX, upperY, lowerX, lowerY - 1, upperX, upperY + 1, lowerX, lowerY,
        cnt);
  int totX = 0;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < m - 2; j++)
      if (field[i][j] == '#' && field[i][j + 1] == '#' &&
          field[i][j + 2] == '#') {
        flag = true;
        break;
      }
    if (flag) axisX[totX++] = i;
  }
  int totY = 0;
  for (int j = 0; j < m; j++) {
    bool flag = false;
    for (int i = 0; i < n - 2; i++)
      if (field[i][j] == '#' && field[i + 1][j] == '#' &&
          field[i + 2][j] == '#') {
        flag = true;
        break;
      }
    if (flag) axisY[totY++] = j;
  }
  if (totX < 2 || totY < 2) {
    printf("NO\n");
    return 0;
  }
  for (int x1 = 0; x1 < totX; x1++) {
    if (x1 != 0 && x1 != 1 && x1 != totX - 2 && x1 != totX - 1) continue;
    for (int y1 = 0; y1 < totY; y1++) {
      if (field[axisX[x1]][axisY[y1]] == '.') continue;
      if (y1 != 0 && y1 != 1 && y1 != totY - 2 && y1 != totY - 1) continue;
      for (int x2 = x1 + 1; x2 < totX; x2++) {
        if (x2 != 0 && x2 != 1 && x2 != totX - 2 && x2 != totX - 1) continue;
        for (int y2 = y1 + 1; y2 < totY; y2++) {
          if (field[axisX[x2]][axisY[y2]] == '.') continue;
          if (!check(axisX[x1], axisY[y1], axisX[x2], axisY[y2])) continue;
          if (y2 != 0 && y2 != 1 && y2 != totY - 2 && y2 != totY - 1) continue;
          for (int x3 = 0; x3 < totX; x3++) {
            if (x3 != 0 && x3 != 1 && x3 != totX - 2 && x3 != totX - 1)
              continue;
            for (int y3 = 0; y3 < totY; y3++) {
              if (field[axisX[x3]][axisY[y3]] == '.') continue;
              if (y3 != 0 && y3 != 1 && y3 != totY - 2 && y3 != totY - 1)
                continue;
              for (int x4 = x3 + 1; x4 < totX; x4++) {
                if (x4 != 0 && x4 != 1 && x4 != totX - 2 && x4 != totX - 1)
                  continue;
                for (int y4 = y3 + 1; y4 < totY; y4++) {
                  if (field[axisX[x4]][axisY[y4]] == '.') continue;
                  if (y4 != 0 && y4 != 1 && y4 != totY - 2 && y4 != totY - 1)
                    continue;
                  judge(axisX[x1], axisY[y1], axisX[x2], axisY[y2], axisX[x3],
                        axisY[y3], axisX[x4], axisY[y4], cnt);
                }
              }
            }
          }
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
