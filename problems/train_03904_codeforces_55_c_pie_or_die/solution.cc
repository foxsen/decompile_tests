#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  bool canW = false;
  for (int i = 0; i < K; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    for (int j = 0; j < M; j++) {
      int d1 = abs(x - 0) + abs(y - j);
      int d2 = abs(x - (N - 1)) + abs(y - j);
      if (d1 <= 4 || d2 <= 4) {
        canW = true;
        break;
      }
    }
    if (!canW) {
      for (int j = 0; j < N; j++) {
        int d1 = abs(x - j) + abs(y - 0);
        int d2 = abs(x - j) + abs(y - (M - 1));
        if (d1 <= 4 || d2 <= 4) {
          canW = true;
          break;
        }
      }
    }
  }
  if (canW)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
