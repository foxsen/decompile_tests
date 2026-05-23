#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  long long int array[t];
  for (int i = 0; i < t; i++) {
    scanf("%lld", &array[i]);
  }
  for (int i = 0; i < t; i++) {
    printf("%d %lld\n", 2, array[i] - 1);
  }
}
