#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct SB {
  int a, b;
  bool friend operator<(SB x, SB y) {
    return x.a < y.a || x.a == y.a && x.b < y.b;
  }
} S[N];
int A[N];
int c[N];
int main() {
  int n, f = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &S[i].a);
    S[i].b = i;
  }
  sort(c + 1, c + n + 1, greater<int>());
  sort(S + 1, S + n + 1);
  for (int i = 1; i <= n; i++) A[S[i].b] = c[i];
  printf("%d", A[1]);
  for (int i = 2; i <= n; i++) printf(" %d", A[i]);
  return 0;
}
