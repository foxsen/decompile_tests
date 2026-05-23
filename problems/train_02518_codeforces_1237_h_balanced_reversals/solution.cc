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
const int N = 4000 + 5;
int T;
int n;
char a[N], b[N];
int A[2][2], B[2][2];
inline void work() {
  scanf("%s %s", a, b);
  n = strlen(a);
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  for (int i = 0; i < n; i += 2) {
    ++A[a[i] - '0'][a[i + 1] - '0'];
    ++B[b[i] - '0'][b[i + 1] - '0'];
  }
  if (A[0][0] != B[0][0] || A[1][1] != B[1][1]) {
    puts("-1");
    return;
  }
  vector<int> res;
  int back = -1;
  if (A[0][1] != B[1][0]) {
    int delta = 0;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == '0' && a[i + 1] == '1') {
        ++delta;
      } else if (a[i] == '1' && a[i + 1] == '0') {
        --delta;
      }
      if (A[0][1] - delta == B[1][0]) {
        res.emplace_back(i + 2);
        reverse(a, a + i + 2);
        break;
      }
    }
    if (res.empty()) {
      delta = 0;
      for (int i = 0; i < n; i += 2) {
        if (b[i] == '1' && b[i + 1] == '0') {
          ++delta;
        }
        if (b[i] == '0' && b[i + 1] == '1') {
          --delta;
        }
        if (B[1][0] - delta == A[0][1]) {
          back = i + 2;
          reverse(b, b + i + 2);
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i += 2) {
    char c = b[n - i - 2], d = b[n - i - 1];
    for (int j = i; j < n; j += 2) {
      if (a[j] == d && a[j + 1] == c) {
        if (j != 0) {
          res.emplace_back(j);
          reverse(a, a + j);
        }
        res.emplace_back(j + 2);
        reverse(a, a + j + 2);
        break;
      }
    }
  }
  if (back != -1) {
    res.emplace_back(back);
  }
  printf("%lu\n", res.size());
  for (const auto &v : res) {
    printf("%d ", v);
  }
  puts("");
}
int main() {
  read(T);
  for (int cas = 0; cas < T; ++cas) {
    work();
  }
}
