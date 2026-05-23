#include <bits/stdc++.h>
using namespace std;
int n, m, q, mp[2000001], R[2000001], D[2000001];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &mp[(i) * (m + 1) + (j)]);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int pos = (i) * (m + 1) + (j);
      R[pos] = (i) * (m + 1) + (j + 1);
      D[pos] = (i + 1) * (m + 1) + (j);
    }
  }
  while (q--) {
    int a, b, c, d, h, w, t1 = 0, t2 = 0, p1, p2;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
    for (int i = 1; i < a; i++) {
      t1 = D[t1];
    }
    for (int i = 1; i < b; i++) {
      t1 = R[t1];
    }
    for (int i = 1; i < c; i++) {
      t2 = D[t2];
    }
    for (int i = 1; i < d; i++) {
      t2 = R[t2];
    }
    p1 = t1;
    p2 = t2;
    for (int i = 1; i <= h; i++) {
      p1 = D[p1];
      p2 = D[p2];
      swap(R[p1], R[p2]);
    }
    for (int i = 1; i <= w; i++) {
      p1 = R[p1];
      p2 = R[p2];
      swap(D[p1], D[p2]);
    }
    p1 = t1;
    p2 = t2;
    for (int i = 1; i <= w; i++) {
      p1 = R[p1];
      p2 = R[p2];
      swap(D[p1], D[p2]);
    }
    for (int i = 1; i <= h; i++) {
      p1 = D[p1];
      p2 = D[p2];
      swap(R[p1], R[p2]);
    }
  }
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    pos = D[pos];
    int now = pos;
    for (int j = 1; j <= m; j++) {
      printf("%d ", mp[now]);
      now = R[now];
    }
    printf("\n");
  }
  return 0;
}
