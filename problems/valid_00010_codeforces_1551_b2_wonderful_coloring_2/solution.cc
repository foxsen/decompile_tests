#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int pos, v, c;
} a[N];
bool operator<(const node p, const node q) { return p.v < q.v; }
int T, n, k, ret[N];
int main() {
  scanf("%d", &T);
  for (int tc = (1); tc <= (T); tc++) {
    scanf("%d%d", &n, &k);
    for (int i = (1); i <= (n); i++) scanf("%d", &a[i].v);
    for (int i = (1); i <= (n); i++) a[i].pos = i, a[i].c = 0;
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1, cnt = 1; i <= n; i++) {
      if (a[i].v == a[i - 1].v)
        cnt++;
      else
        cnt = 1;
      if (cnt <= k)
        m++;
      else
        a[i].c = -1;
    }
    m /= k;
    for (int i = 1, t = 1, col = 1; i <= n && t <= m; i++)
      if (a[i].c != -1) {
        a[i].c = col;
        col++;
        if (col > k) {
          col = 1;
          t++;
        }
      }
    for (int i = (1); i <= (n); i++)
      ret[a[i].pos] = (a[i].c == -1 ? 0 : a[i].c);
    for (int i = (1); i <= (n); i++) printf("%d ", ret[i]);
    puts("");
  }
  return 0;
}
