#include <bits/stdc++.h>
int main() {
  int n, k, p;
  int tree[1001];
  int i, j, b, sum, f, w = 1;
  scanf("%d%d", &n, &k);
  p = n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &tree[i]);
  }
  for (i = 1; i <= n; i++) {
    b = tree[i];
    sum = 0;
    if (b - (i - 1) * k <= 0) continue;
    f = b - (i - 1) * k;
    for (j = 1; j <= i; j++) {
      if (tree[j] != f + (j - 1) * k) sum++;
    }
    for (j = i + 1; j <= n; j++) {
      if (tree[j] != b + (j - i) * k) sum++;
    }
    if (sum < p) {
      p = sum;
      w = i;
    }
  }
  printf("%d\n", p);
  b = tree[w];
  f = b - (w - 1) * k;
  for (j = 1; j <= w; j++) {
    if (tree[j] != f + (j - 1) * k)
      if (tree[j] < f + (j - 1) * k)
        printf("+ %d %d\n", j, f + (j - 1) * k - tree[j]);
      else
        printf("- %d %d\n", j, tree[j] - f - (j - 1) * k);
  }
  for (j = w + 1; j <= n; j++) {
    if (tree[j] != b + (j - w) * k)
      if (tree[j] < b + (j - w) * k)
        printf("+ %d %d\n", j, b + (j - w) * k - tree[j]);
      else
        printf("- %d %d\n", j, tree[j] - b - (j - w) * k);
  }
  return 0;
}
