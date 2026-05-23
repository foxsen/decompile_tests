#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  int a[N], b[N];
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int fst = b[0], sum = a[0], rslt = 0;
  for (int i = 1; i < N; i++) {
    if (b[i] < fst) {
      rslt += sum * fst;
      fst = b[i], sum = a[i];
    } else
      sum += a[i];
  }
  rslt += sum * fst;
  printf("%d\n", rslt);
  return 0;
}
