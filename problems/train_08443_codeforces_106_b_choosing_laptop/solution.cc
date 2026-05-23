#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, c, d, e;
} s[110], s1[110];
bool cmp(node x, node y) { return x.d < y.d; }
int main() {
  int n;
  scanf("%d", &n);
  int p = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z, w;
    scanf("%d%d%d%d", &x, &y, &z, &w);
    s[i].a = x;
    s[i].b = y;
    s[i].c = z;
    s[i].d = w;
  }
  int a[110];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      for (int j = 0; j < n; j++) {
        if (!a[j]) {
          if (s[i].a < s[j].a && s[i].b < s[j].b && s[i].c < s[j].c) {
            a[i] = 1;
          } else if (s[i].a > s[j].a && s[i].b > s[j].b && s[i].c > s[j].c) {
            a[j] = 1;
          }
        }
      }
    }
  }
  int k = -1;
  int h = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      if (h > s[i].d) {
        h = s[i].d;
        k = i;
      }
    }
  }
  printf("%d\n", k + 1);
  return 0;
}
