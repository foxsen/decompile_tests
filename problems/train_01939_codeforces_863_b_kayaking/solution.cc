#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, a, p, N, A, nb[108];
  while (scanf("%d", &N) == 1) {
    A = 1 << 20;
    N *= 2;
    for (i = 0; i < N; i++) scanf("%d", &nb[i]);
    sort(nb, nb + N);
    for (i = 0; i < N - 1; i++)
      for (j = i + 1; j < N; j++) {
        a = 0;
        p = (-1);
        for (k = 0; k < N; k++)
          if (k != i && k != j)
            if (p < 0)
              p = nb[k];
            else {
              a += abs(p - nb[k]);
              p = (-1);
            }
        A = min(A, a);
      }
    printf("%d\n", A);
  }
  return 0;
}
