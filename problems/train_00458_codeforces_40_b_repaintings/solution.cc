#include <bits/stdc++.h>
using namespace std;
int perimeter(int w, int h) {
  if (w == 1) return h;
  if (h == 1) return w;
  return 2 * w + 2 * (h - 2);
}
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int res = 0;
  while (true) {
    int border = (perimeter(n, m) + 1) / 2;
    --x;
    if (!x) {
      res = border;
      break;
    }
    n -= 2;
    m -= 2;
    if (n <= 0 || m <= 0) {
      break;
    }
  }
  cout << res << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
