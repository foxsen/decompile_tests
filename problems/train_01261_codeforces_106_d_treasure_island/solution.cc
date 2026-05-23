#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
char grid[MAX][MAX];
int n, m;
pair<int, int> pos[30];
int row[MAX][MAX], col[MAX][MAX];
inline bool inside(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}
int row_wet(pair<int, int> a, pair<int, int> b) {
  if (a.second > b.second) {
    swap(a, b);
  }
  return row[a.first][b.second] - row[a.first][a.second - 1];
}
int col_wet(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) {
    swap(a, b);
  }
  return col[a.second][b.first] - col[a.second][a.first - 1];
}
int main() {
  memset(pos, -1, sizeof pos);
  scanf("%d %d%*c", &n, &m);
  for (int i = int(1); i < int(n + 1); i++) {
    for (int j = int(1); j < int(m + 1); j++) {
      scanf("%c", &grid[i][j]);
      if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
        pos[grid[i][j] - 'A'] = pair<int, int>(i, j);
        grid[i][j] = '.';
      }
    }
    scanf("%*c");
  }
  for (int i = int(1); i < int(n + 1); i++) {
    for (int j = int(1); j < int(m + 1); j++) {
      row[i][j] = row[i][j - 1] + (grid[i][j] == '#');
    }
  }
  for (int j = int(1); j < int(m + 1); j++) {
    for (int i = int(1); i < int(n + 1); i++) {
      col[j][i] = col[j][i - 1] + (grid[i][j] == '#');
    }
  }
  int k;
  scanf("%d%*c", &k);
  vector<pair<int, int> > ins;
  for (int i = int(0); i < int(k); i++) {
    char c;
    int t;
    scanf("%c %d%*c", &c, &t);
    if (c == 'N') {
      ins.emplace_back(-t, 0);
    } else if (c == 'S') {
      ins.emplace_back(t, 0);
    } else if (c == 'W') {
      ins.emplace_back(0, -t);
    } else if (c == 'E') {
      ins.emplace_back(0, t);
    }
  }
  int total = 0;
  for (int i = int(0); i < int(26); i++) {
    if (pos[i].first == -1) {
      continue;
    }
    bool good = true;
    pair<int, int> cur = pos[i];
    for (auto &each : ins) {
      pair<int, int> nxt =
          pair<int, int>(cur.first + each.first, cur.second + each.second);
      if (!inside(nxt.first, nxt.second)) {
        good = false;
        break;
      }
      if (each.first == 0) {
        if (row_wet(cur, nxt)) {
          good = false;
          break;
        }
      } else {
        if (col_wet(cur, nxt)) {
          good = false;
        }
      }
      cur = nxt;
    }
    if (good) {
      printf("%c", 'A' + i);
      total++;
    }
  }
  if (total == 0) {
    puts("no solution");
  } else {
    puts("");
  }
  return 0;
}
