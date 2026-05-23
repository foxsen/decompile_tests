#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
int k, n;
int a[4111];
int p[4111], q[4111], v[4111], pos[4111];
void Fix(int i, int j) {
  int t = pos[v[i] ^ q[i]];
  if (t == i) return;
  if (t == j) {
    swap(p[i], p[j]), swap(pos[p[i]], pos[p[j]]);
    v[i] = p[i] ^ q[i], v[j] = p[j] ^ q[j];
    return;
  }
  swap(p[t], p[i]), swap(pos[p[t]], pos[p[i]]);
  swap(q[t], q[j]);
  Fix(t, j);
}
int main() {
  read(k), n = 1 << k;
  int xorsum = 0;
  for (int i = 0; i < n; ++i) read(a[i]), xorsum ^= a[i];
  if (xorsum) return puts("Fou"), 0;
  puts("Shi");
  for (int i = 0; i < n; ++i) p[i] = q[i] = pos[i] = i;
  for (int i = 0; i < n - 1; ++i) {
    v[n] = a[i] ^ v[i], v[i] ^= v[n], v[i + 1] ^= v[n];
    Fix(i, i + 1);
  }
  for (int i = 0; i < n; ++i) printf("%d ", p[i]);
  puts("");
  for (int i = 0; i < n; ++i) printf("%d ", q[i]);
  puts("");
  return 0;
}
