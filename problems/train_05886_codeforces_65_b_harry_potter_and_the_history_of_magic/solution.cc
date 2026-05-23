#include <bits/stdc++.h>
using namespace std;
const int nmax = 1100;
int a[nmax];
int cnt;
int v[nmax];
void genAll(int x) {
  cnt = 0;
  int t[4], g[4];
  for (int i = 0; i < 4; ++i) {
    t[i] = x % 10;
    x /= 10;
  }
  for (int i = 0; i < 4; ++i) {
    memcpy(g, t, sizeof(t));
    for (int j = 0; j < 10; ++j) {
      g[i] = j;
      int p = 0;
      for (int k = 3; k >= 0; --k) {
        p *= 10;
        p += g[k];
      }
      v[cnt] = p;
      ++cnt;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  bool good = true;
  int prev = 1000;
  for (int i = 0; i < n; ++i) {
    genAll(a[i]);
    a[i] = *max_element(v, v + cnt);
    for (int j = 0; j < cnt; ++j) {
      if (v[j] <= 2011 && v[j] >= prev && v[j] < a[i]) {
        a[i] = v[j];
      }
    }
    if (a[i] < prev || a[i] > 2011) {
      good = false;
      break;
    }
    prev = a[i];
  }
  if (!good) {
    puts("No solution");
  } else {
    for (int i = 0; i < n; ++i) {
      printf("%d\n", a[i]);
    }
  }
  return 0;
}
