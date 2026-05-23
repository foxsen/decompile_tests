#include <bits/stdc++.h>
using namespace std;
int prime[5000001];
void SieveOfEratosthenes() {
  int i, p;
  for (i = 2; i < 5000001; i += 2) prime[i] = 2;
  for (p = 3; p < 5000001; p += 2) {
    if (!(prime[p])) {
      prime[p] = p;
      for (i = p * 3; i < 5000001; i += (2 * p)) prime[i] = p;
    }
  }
}
int aux[5000001], res[5000001];
int main() {
  SieveOfEratosthenes();
  int i, t, a, b;
  aux[1] = 0;
  for (i = 2; i < 5000001; i++) {
    aux[i] = aux[i / prime[i]] + 1;
    res[i] = res[i - 1] + aux[i];
  }
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d%d", &b, &a);
    printf("%d\n", res[b] - res[a]);
  }
}
