#include <bits/stdc++.h>
using namespace std;
const int N = 10001, oo = (1 << 29);
int n;
int arr[N];
int r = 5000, c = -1, mxUp = r, mxDown = r;
bool up = true;
char g[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
  for (int i = 0; i < n; ++i) {
    int temp = arr[i];
    if (up) {
      if (temp == 1) {
        g[r][++c] = '/';
      } else {
        g[r][++c] = '/';
        while (temp > 1) {
          g[--r][++c] = '/';
          --temp;
        }
      }
      mxUp = min(mxUp, r);
    } else {
      if (temp == 1) {
        g[r][++c] = '\\';
      } else {
        g[r][++c] = '\\';
        while (temp > 1) {
          g[++r][++c] = '\\';
          --temp;
        }
      }
      mxDown = max(mxDown, r);
    }
    up = !up;
  }
  for (int i = mxUp; i <= mxDown; ++i) {
    for (int j = 0; j <= c; ++j)
      printf("%c", ((g[i][j] != '\\' && g[i][j] != '/') ? ' ' : g[i][j]));
    puts("");
  }
  return 0;
}
