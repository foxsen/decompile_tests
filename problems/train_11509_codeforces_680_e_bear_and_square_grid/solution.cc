#include <bits/stdc++.h>
using namespace std;
int n, k, z[510][510], used[510][510], second[250000], u[250000], ans = -1;
char a[510][510];
vector<int> v;
void dfs(int i, int j, int t) {
  used[i][j] = t;
  if (i + 1 < n && !used[i + 1][j] && a[i + 1][j] == '.') dfs(i + 1, j, t);
  if (j + 1 < n && !used[i][j + 1] && a[i][j + 1] == '.') dfs(i, j + 1, t);
  if (j - 1 >= 0 && !used[i][j - 1] && a[i][j - 1] == '.') dfs(i, j - 1, t);
  if (i - 1 >= 0 && !used[i - 1][j] && a[i - 1][j] == '.') dfs(i - 1, j, t);
}
int first(int x, int y) {
  int i, j, res = 0;
  i = x - 1;
  for (j = y; j < y + k && i >= 0; j++) {
    if (j < 0) continue;
    if (a[i][j] == '.' && !u[used[i][j]])
      res += second[used[i][j]], u[used[i][j]] = 1, v.push_back(used[i][j]);
  }
  i = x + k;
  for (j = y; j < y + k && i < n; j++) {
    if (j < 0) continue;
    if (a[i][j] == '.' && !u[used[i][j]])
      res += second[used[i][j]], u[used[i][j]] = 1, v.push_back(used[i][j]);
  }
  j = y - 1;
  for (i = x; i >= 0 && i < x + k && j >= 0; i++) {
    if (a[i][j] == '.' && !u[used[i][j]])
      res += second[used[i][j]], u[used[i][j]] = 1, v.push_back(used[i][j]);
  }
  j = y + k;
  for (i = x; i >= 0 && i < x + k && j < n; i++) {
    if (a[i][j] == '.' && !u[used[i][j]])
      res += second[used[i][j]], u[used[i][j]] = 1, v.push_back(used[i][j]);
  }
  res += k * k;
  for (i = 0; i < v.size(); i++) u[v[i]] = 0;
  v.clear();
  return res;
}
int main() {
  int i, j, l, h;
  int t = 0;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '.' && !used[i][j]) {
        t++;
        dfs(i, j, t);
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '.') second[used[i][j]]++;
    }
  }
  if (a[0][0] == 'X') z[0][0] = 1;
  for (i = 1; i < n; i++) {
    z[i][0] = z[i - 1][0];
    if (a[i][0] == 'X') z[i][0]++;
    z[0][i] = z[0][i - 1];
    if (a[0][i] == 'X') z[0][i]++;
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j < n; j++) {
      z[i][j] = z[i - 1][j] + z[i][j - 1] - z[i - 1][j - 1];
      if (a[i][j] == 'X') z[i][j]++;
    }
  }
  for (i = 0; i < n - k + 1; i++) {
    for (j = 0; j < n - k + 1; j++) {
      if (j == 0) {
        for (l = i; l < i + k; l++) {
          for (h = 0; h < k; h++) {
            if (a[l][h] == '.') second[used[l][h]]--;
          }
        }
      } else {
        h = j - 1;
        for (l = i; l < i + k; l++) {
          if (a[l][h] == '.') second[used[l][h]]++;
        }
        h = j + k - 1;
        for (l = i; l < i + k; l++) {
          if (a[l][h] == '.') second[used[l][h]]--;
        }
      }
      int r = first(i, j);
      if (r > ans) {
        ans = r;
      }
    }
    for (l = i; l < i + k; l++) {
      for (h = n - k; h < n; h++) {
        if (a[l][h] == '.') second[used[l][h]]++;
      }
    }
  }
  cout << ans << endl;
}
