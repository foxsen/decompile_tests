#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const double EPS = 1e-9;
const int MaxN = 100000 + 5;
int N, A[MaxN];
int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  sort(A, A + N);
  if (A[N - 1] != 1) {
    printf("%d", 1);
    for (int i = 1; i < N; i++) printf(" %d", A[i - 1]);
    printf("\n");
  } else {
    for (int i = 0; i < N - 1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N - 1] + 1);
  }
  return 0;
}
