#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int x = 0, neg = 1;
  char op = getchar();
  while (!isdigit(op)) {
    if (op == '-') neg = -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = 10 * x + op - '0';
    op = getchar();
  }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1002;
int a[N], n;
stack<pair<int, int>> ans;
bool check() {
  for (register int i = 1; i <= n; i++)
    if (i != a[i]) return 0;
  return 1;
}
void dfs(int dep) {
  if (check()) {
    printf("%d\n", ans.size());
    while (!ans.empty()) {
      pair<int, int> fir = ans.top();
      ans.pop();
      printf("%d %d\n", fir.first, fir.second);
    }
    exit(0);
  }
  if (!dep) return;
  for (register int i = 1; i <= n; i++) {
    if (a[i] != i && (abs(a[i] - a[i - 1]) != 1 || abs(a[i] - a[i + 1]) != 1)) {
      for (register int j = i + 1; j <= n; j++) {
        if (a[j] != j &&
            (abs(a[j] - a[j - 1]) != 1 || abs(a[j] - a[j + 1]) != 1)) {
          ans.push(make_pair(i, j));
          reverse(a + i, a + j + 1);
          dfs(dep - 1);
          reverse(a + i, a + j + 1);
          ans.pop();
        }
      }
    }
  }
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) a[i] = read();
  a[0] = a[n + 1] = -1;
  dfs(3);
  return 0;
}
