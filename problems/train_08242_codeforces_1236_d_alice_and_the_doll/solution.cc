#include <bits/stdc++.h>
using namespace std;
long long m, n, flag, x = 1, y = 1, k;
const int maxn = 1e5 + 5;
vector<long long> line[maxn];
vector<long long> col[maxn];
struct node {
  int x, y;
} last;
bool fun(int x, int y) {
  if (last.x == x && last.y == y) return true;
  return false;
}
void run(long long ans) {
  if (ans + k == n * m)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    line[x].push_back(y);
    col[y].push_back(x);
  }
  for (int i = 0; i < maxn; i++) sort(line[i].begin(), line[i].end());
  for (int i = 0; i < maxn; i++) sort(col[i].begin(), col[i].end());
  int a = 0, b = m + 1, c = 1, d = n + 1;
  long long ans = 1;
  x = 1, y = 1;
  while (1) {
    int i;
    for (i = 0; i < line[x].size(); i++) {
      if (line[x][i] > y && line[x][i] < b) {
        if (line[x][i] - y == 1 && fun(x, y)) {
          run(ans);
          return 0;
        }
        ans += line[x][i] - y - 1;
        y = line[x][i] - 1;
        b = y;
        last.x = x;
        last.y = y;
        break;
      }
    }
    if (i == line[x].size()) {
      if (y + 1 == b && fun(x, y)) {
        run(ans);
        return 0;
      }
      ans += b - y - 1;
      y = --b;
      last.x = x;
      last.y = y;
    }
    for (i = 0; i < col[y].size(); i++) {
      if (col[y][i] > x && col[y][i] < d) {
        if (col[y][i] - x == 1 && fun(x, y)) {
          run(ans);
          return 0;
        }
        ans += col[y][i] - x - 1;
        x = col[y][i] - 1;
        d = x;
        last.x = x;
        last.y = y;
        break;
      }
    }
    if (i == col[y].size()) {
      if (d - x == 1 && fun(x, y)) {
        run(ans);
        return 0;
      }
      ans += d - x - 1;
      x = --d;
      last.x = x;
      last.y = y;
    }
    for (i = line[x].size() - 1; i >= 0; i--) {
      if (line[x][i] < y && line[x][i] > a) {
        if (y - line[x][i] == 1 && fun(x, y)) {
          run(ans);
          return 0;
        }
        ans += y - line[x][i] - 1;
        y = line[x][i] + 1;
        a = y;
        last.x = x;
        last.y = y;
        break;
      }
    }
    if (i == -1) {
      if (y - a == 1 && fun(x, y)) {
        run(ans);
        return 0;
      }
      ans += y - a - 1;
      y = ++a;
      last.x = x;
      last.y = y;
    }
    for (i = col[y].size() - 1; i >= 0; i--) {
      if (col[y][i] < x && col[y][i] > c) {
        if (x - col[y][i] == 1 && fun(x, y)) {
          run(ans);
          return 0;
        }
        ans += x - col[y][i] - 1;
        x = col[y][i] + 1;
        c = x;
        last.x = x;
        last.y = y;
        break;
      }
    }
    if (i == -1) {
      if (x - c == 1 && fun(x, y)) {
        run(ans);
        return 0;
      }
      ans += x - c - 1;
      x = ++c;
      last.x = x;
      last.y = y;
    }
  }
  return 0;
}
