#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void read(Tp &x) {
  static char c;
  static bool neg;
  x = 0, c = getchar(), neg = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') {
      neg = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (neg) {
    x = -x;
  }
}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
int n, s;
int in[N];
int main() {
  read(n), read(s);
  for (int i = 1, u, v; i < n; ++i) {
    read(u), read(v);
    ++in[u], ++in[v];
  }
  int leaf = 0;
  for (int i = 1; i <= n; ++i) {
    if (in[i] == 1) {
      ++leaf;
    }
  }
  printf("%.8f\n", 2.0 / leaf * s);
}
