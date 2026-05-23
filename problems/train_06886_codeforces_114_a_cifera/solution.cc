#include <bits/stdc++.h>
using namespace std;
int main() {
  int K, L;
  while (scanf("%d", &K) == 1) {
    scanf("%d", &L);
    if (L < K)
      puts("NO");
    else if (L == K)
      printf("YES\n0\n");
    else {
      int ret = -1;
      long long hitung = K;
      for (int i = 1;; i++) {
        hitung *= K;
        if (hitung == L)
          ret = i;
        else if (hitung > L)
          break;
      }
      if (ret == -1)
        puts("NO");
      else {
        puts("YES");
        printf("%d\n", ret);
      }
    }
  }
  return 0;
}
