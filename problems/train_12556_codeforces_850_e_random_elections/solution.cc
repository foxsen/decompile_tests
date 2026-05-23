#include <bits/stdc++.h>
const int maxn = 1048600;
int n, m;
char s[maxn];
int a[maxn], bits[maxn];
long long b[maxn], ans;
template <typename T>
inline void FWT(T *a) noexcept {
  T *End = a + n;
  for (register int hl = 1, l = 2; hl < n; hl = l, l <<= 1) {
    for (register T *i = a; i != End; i += l) {
      T *tmp = i + hl, *j = i, *k = tmp;
      for (; j != tmp; ++j, ++k) {
        T foo = *j;
        *j += *k;
        *k = foo - *k;
      }
    }
  }
  return;
}
int main(int argc, char const *argv[]) {
  scanf("%d", &m);
  n = 1 << m;
  fread(s, 1, maxn, stdin);
  char *S = s;
  while (*S != '0' && *S != '1') {
    ++S;
  }
  a[0] = *S - '0';
  ++S;
  for (register int i = 1; i < n; ++i) {
    a[i] = *S - '0';
    ++S;
    bits[i] = bits[i ^ (i & -i)] + 1;
  }
  FWT(a);
  for (register int i = 0; i < n; ++i) {
    b[i] = 1ll * a[i] * a[i];
  }
  FWT(b);
  for (register int i = 0; i < n; ++i) {
    ans += b[i] >> bits[i];
  }
  printf("%d\n", 3ll * ans % 1000000007);
  return 0;
}
