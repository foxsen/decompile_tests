#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int N, M, a, b, C[128];
int main(void) {
  scanf("%d%d", &N, &M);
  for (int i(0); i < M; i++) {
    scanf("%d%d", &a, &b);
    for (int k(--a); k < b; k++) ++C[k];
  }
  for (int i(0); i < N; i++)
    if (C[i] ^ 1) return printf("%d %d\n", i + 1, C[i]), 0;
  puts("OK");
  return 0;
}
