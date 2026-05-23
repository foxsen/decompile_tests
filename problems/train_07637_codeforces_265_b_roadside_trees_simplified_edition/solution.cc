#include <bits/stdc++.h>
int main() {
  int Timer = 0, H, N, H1, Contador, Bajada, fu;
  scanf("%d", &N);
  fu = 0;
  scanf("%d", &H1);
  Timer = Timer + H1 + 1;
  for (Contador = 1; Contador < N; Contador++) {
    scanf("%d", &H);
    if (H == H1) {
      Timer += 2;
    } else if (H < H1) {
      Bajada = H1 - H;
      Timer = Timer + Bajada + 2;
    } else {
      int Subida = H - H1;
      Timer = Timer + Subida + 2;
    }
    H1 = H;
  }
  printf("%d", Timer);
  return 0;
}
