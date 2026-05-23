#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int n;
  scanf("%d", &n);
  int time[n];
  int i, sum_time = 0, penalty = 0, resuelto = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &time[i]);
  }
  qsort(time, n, sizeof(int), cmpfunc);
  for (i = 0; i < n; i++) {
    sum_time += time[i];
    if (sum_time > 350 && sum_time <= 710) {
      penalty += sum_time - 350;
    }
    if (sum_time <= 710) {
      resuelto++;
    }
  }
  printf("%d %d", resuelto, penalty);
  return 0;
}
