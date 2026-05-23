#include <bits/stdc++.h>
using namespace std;
long long Q, rM;
long long A[505050];
long long mdm[800][800];
long long i, j, k, l;
int main() {
  for (rM = 0; rM * rM <= 500000; rM++)
    ;
  scanf("%lld", &Q);
  while (Q--) {
    long long T, X, Y;
    scanf("%lld%lld%lld", &T, &X, &Y);
    if (T == 1) {
      A[X] += Y;
      for (i = 1; i < rM; i++) {
        mdm[i][X % i] += Y;
      }
    } else {
      if (X < rM) {
        printf("%lld\n", mdm[X][Y]);
      } else {
        long long ans = 0;
        for (i = Y; i <= 500000; i += X) {
          ans += A[i];
        }
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
