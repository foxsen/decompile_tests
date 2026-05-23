#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 310;
const int M = 5000;
const int oo = 10000 * 10000 * 10;
int n, m, nth;
char g[N][N];
bool go(int x) {
  int i, j, k;
  for (i = 1 + x; i + x <= n; ++i) {
    for (j = 1 + x; j + x <= m; ++j) {
      if (g[i][j] == '*' && g[i - x][j] == '*' && g[i + x][j] == '*' &&
          g[i][j + x] == '*' && g[i][j - x] == '*') {
        --nth;
        if (nth == 0) {
          printf("%d %d\n", i, j);
          printf("%d %d\n", i - x, j);
          printf("%d %d\n", i + x, j);
          printf("%d %d\n", i, j - x);
          printf("%d %d\n", i, j + x);
          return true;
        }
      }
    }
  }
  return false;
}
int main() {
  int i, j, cas = 0;
  scanf("%d %d %d", &n, &m, &nth);
  for (i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
  for (i = 1; i <= n; ++i)
    if (go(i)) {
      return 0;
    }
  puts("-1");
  return 0;
}
