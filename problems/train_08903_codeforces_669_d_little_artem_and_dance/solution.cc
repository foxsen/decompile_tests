#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  pair<int, int> a;
  a.first = 0;
  a.second = 0;
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      if (x % 2 == 1 || x % 2 == -1) {
        int v = a.first;
        a.first = a.second;
        a.second = v;
      }
      a.first = (a.first + x) % n;
      a.second = (a.second + x) % n;
    } else {
      a.first += 1;
      a.second -= 1;
      int v = a.first;
      a.first = a.second;
      a.second = v;
    }
  }
  for (int i = 0; i < n; i++) {
    int d = a.first;
    if (i % 2 == 1) d = a.second;
    printf("%d ", (i - d + 10 * n) % n + 1);
  }
  return 0;
}
