#include <bits/stdc++.h>
using namespace std;
long long N, P;
double M;
int main() {
  scanf("%lld", &N);
  if (N < 10) {
    printf("1\n");
    return 0;
  }
  long long k = 10;
  while (k * 10 <= N) k *= 10;
  M = N;
  M /= k;
  P = (long long)ceil(M) * k;
  if (P == N) P += k;
  cout << P - N << endl;
}
