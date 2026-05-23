#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ant;
  scanf("%d", &ant);
  int max_mes = 0;
  for (int i = 1; i < n; i++) {
    int aux;
    scanf("%d", &aux);
    if (aux < ant) max_mes = i;
    ant = aux;
  }
  printf("%d\n", max_mes);
  return 0;
}
