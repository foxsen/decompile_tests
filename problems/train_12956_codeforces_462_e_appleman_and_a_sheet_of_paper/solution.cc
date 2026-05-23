#include <bits/stdc++.h>
using namespace std;
const int maxn = 101000;
int a[maxn], n, q;
inline int lowbit(int x) { return x & (-x); }
void add(int p, int v) {
  for (int i = p; i <= n; i += lowbit(i)) a[i] += v;
}
int sum(int p) {
  int sum = 0;
  for (int i = p; i; i -= lowbit(i)) sum += a[i];
  return sum;
}
int main() {
  scanf("%d%d", &n, &q);
  int flag = 0;
  for (int i = 1; i <= n; i++) add(i, 1);
  int beg = 1, end = n;
  while (q--) {
    int k, p, l, r;
    scanf("%d", &k);
    if (k == 1) {
      scanf("%d", &p);
      if (p <= (end - beg + 1) / 2) {
        if (flag == 0) {
          for (int i = p + beg - 1, j = p + beg; i >= beg; i--, j++) {
            add(j, sum(i) - sum(i - 1));
          }
          beg = beg + p;
        } else {
          for (int i = end - p, j = end - p + 1; j <= end; i--, j++) {
            add(i, sum(j) - sum(j - 1));
          }
          end = end - p;
        }
      } else {
        if (flag == 0) {
          for (int i = beg + p - 1, j = p + beg; j <= end; j++, i--) {
            add(i, sum(j) - sum(j - 1));
          }
          end = beg + p - 1;
        } else {
          for (int i = end - p, j = end - p + 1; i >= beg; i--, j++) {
            add(j, sum(i) - sum(i - 1));
          }
          beg = end - p + 1;
        }
        flag = flag ^ 1;
      }
    } else if (k == 2) {
      scanf("%d%d", &l, &r);
      l++;
      if (flag == 0) {
        l = beg + l - 1;
        r = beg + r - 1;
        printf("%d\n", sum(r) - sum(l - 1));
      } else {
        l = end - l + 1;
        r = end - r + 1;
        printf("%d\n", sum(l) - sum(r - 1));
      }
    }
  }
  return 0;
}
