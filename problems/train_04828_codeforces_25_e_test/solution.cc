#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
template <class T>
inline T sqr(T x) {
  return x * x;
}
char a[3][1 << 17];
int n[3], m;
char s[1 << 18];
int p[1 << 18];
void kmp() {
  p[0] = 0;
  for (int i = 1; i < m; ++i) {
    int j = p[i - 1];
    for (; j && s[i] != s[j]; j = p[j - 1])
      ;
    if (s[i] == s[j]) ++j;
    p[i] = j;
  }
}
int main() {
  for (int i = 0; i < 3; ++i) {
    gets(a[i]);
    n[i] = strlen(a[i]);
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == j || !n[i] || !n[j]) continue;
      sprintf(s, "%s#%s", a[i], a[j]);
      m = n[i] + n[j] + 1;
      kmp();
      if (find(p + n[i] + 1, p + m, n[i]) != p + m) n[i] = 0;
    }
  }
  int id[] = {0, 1, 2};
  int res = n[0] + n[1] + n[2];
  do {
    int tmp = n[0] + n[1] + n[2];
    for (int i = 2; i; --i) {
      int i1 = id[i], i2 = id[i - 1];
      if (!n[i1] || !n[i2]) continue;
      sprintf(s, "%s#%s", a[i1], a[i2]);
      m = n[i1] + n[i2] + 1;
      kmp();
      tmp -= p[m - 1];
    }
    res = min(res, tmp);
  } while (next_permutation(id, id + 3));
  printf("%d\n", res);
  return 0;
}
