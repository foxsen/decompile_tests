#include <bits/stdc++.h>
using namespace std;
const int MN = 100111;
int n, M, T;
int a[MN], bit[MN], res[MN];
int get(int u) {
  int res = 0;
  while (u > 0) {
    res += bit[u];
    u -= ((u) & (-(u)));
  }
  return res;
}
void update(int u, int val) {
  while (u < MN) {
    bit[u] += val;
    u += ((u) & (-(u)));
  }
}
int main() {
  while (scanf("%d%d%d", &n, &M, &T) == 3) {
    for (int i = (1), _b = (n); i <= _b; i++) {
      int h, m, s;
      scanf("%d:%d:%d", &h, &m, &s);
      a[i] = h * 3600 + m * 60 + s + 1;
    }
    memset(bit, 0, sizeof bit);
    bool ok = false;
    for (int i = (1), _b = (n); i <= _b; i++) {
      int x = a[i] - T + 1;
      if (x < 0) x = 0;
      int has = get(a[i]);
      if (x) has -= get(x - 1);
      if (has + 1 >= M) ok = true;
      if (has < M) {
        res[i] = res[i - 1] + 1;
        update(a[i], 1);
      } else {
        res[i] = res[i - 1];
        update(a[i - 1], -1);
        update(a[i], 1);
      }
    }
    if (!ok)
      cout << "No solution" << endl;
    else {
      printf("%d\n", res[n]);
      for (int i = (1), _b = (n); i <= _b; i++) printf("%d\n", res[i]);
    }
  }
  return 0;
}
